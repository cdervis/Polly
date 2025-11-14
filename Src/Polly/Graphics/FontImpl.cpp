// Copyright (C) 2025 Cem Dervis
// This file is part of Polly.
// For conditions of distribution and use, see copyright notice in LICENSE, or https://polly2d.org.

#include "Polly/Graphics/FontImpl.hpp"

#include "Polly/Defer.hpp"
#include "Polly/Game/GameImpl.hpp"
#include "Polly/Graphics/PainterImpl.hpp"
#include "Polly/Logging.hpp"
#include "Polly/Narrow.hpp"

#if polly_have_gfx_d3d11
#include "Polly/Graphics/D3D11/D3D11Image.hpp"
#include "Polly/Graphics/D3D11/D3D11Painter.hpp"
#endif

#if polly_have_gfx_metal
#include "Polly/Graphics/Metal/MetalImage.hpp"
#endif

#if polly_have_gfx_opengl
#include "Polly/Graphics/OpenGL/OpenGLImage.hpp"
#endif

#define STB_TRUETYPE_IMPLEMENTATION
#include "imstb_truetype.h"

#include "Noto.ttf.hpp"

namespace Polly
{
static auto sBuiltInFontRegular = UniquePtr<Font::Impl>();

Font::Impl::Impl(Span<u8> data, bool createCopyOfData, [[maybe_unused]] bool isBuiltin)
#ifndef NDEBUG
    : _isBuiltin(isBuiltin)
#endif
{
    if (createCopyOfData)
    {
        _ownedFontData.resize(data.size());
        std::ranges::copy(data, _ownedFontData.end());
    }
    else
    {
        _foreignFontData = data.data();
    }

    initialize();
}

Font::Impl::Impl(List<u8> data)
    : _ownedFontData(std::move(data))
{
    initialize();
}

void Font::Impl::createBuiltInFonts()
{
    logVerbose("Creating built-in font objects");

    sBuiltInFontRegular = makeUnique<Impl>(Noto_ttfSpan(), false, true);
    sBuiltInFontRegular->setAssetName("//BuiltIn");
    sBuiltInFontRegular->addRef();
}

void Font::Impl::destroyBuiltInFonts()
{
    sBuiltInFontRegular = {};
}

Font::Impl& Font::Impl::builtIn()
{
    return *sBuiltInFontRegular;
}

Vec2 Font::Impl::measure(StringView text, float fontSize) const
{
    auto left   = 0.0f;
    auto right  = 0.0f;
    auto top    = 0.0f;
    auto bottom = 0.0f;

    forEachGlyph(
        text,
        fontSize,
        [&](char32_t, const Rectangle& rect)
        {
            left   = min(left, rect.left());
            right  = max(right, rect.right());
            top    = min(top, rect.top());
            bottom = max(bottom, rect.bottom());
            return true;
        });

    return Vec2(right - left, bottom - top);
}

const Font::Impl::FontPage& Font::Impl::page(u32 index) const
{
    return _pages[index];
}

const Font::Impl::RasterizedGlyph& Font::Impl::rasterizedGlyph(char32_t codepoint, float fontSize)
{
    if (!_initializedSizes.contains(fontSize))
    {
        // This is the first time we're encountering this font size.

        for (char32_t c = 32; c < 255; ++c)
        {
            std::ignore = rasterizeGlyph(
                RasterizedGlyphKey{
                    .codepoint = c,
                    .fontSize  = fontSize,
                });
        }

        _initializedSizes.add(fontSize);
    }

    const auto key = RasterizedGlyphKey{
        .codepoint = codepoint,
        .fontSize  = fontSize,
    };

    if (const auto glyph = _rasterizedGlyphs.find(key))
    {
        return *glyph;
    }

    return rasterizeGlyph(key);
}

float Font::Impl::lineHeight(float fontSize) const
{
    const auto scale   = stbtt_ScaleForPixelHeight(&_fontInfo, fontSize);
    const auto ascent  = double(_ascent) * scale;
    const auto descent = double(_descent) * scale;
    const auto lineGap = double(_lineGap) * scale;

    return float(ascent - descent + lineGap);
}

void Font::Impl::initialize()
{
    const auto* data = _foreignFontData ? _foreignFontData : _ownedFontData.data();

    if (stbtt_InitFont(&_fontInfo, data, 0) == 0)
    {
        throw Error("Failed to load the font.");
    }

    stbtt_GetFontVMetrics(&_fontInfo, &_ascent, &_descent, &_lineGap);
}

const Font::Impl::RasterizedGlyph& Font::Impl::rasterizeGlyph(const RasterizedGlyphKey& key)
{
    if (_pages.isEmpty())
    {
        appendNewPage();
    }

    assume(_currentPageIndex);

    const auto fontSize = key.fontSize;
    const auto scale    = stbtt_ScaleForPixelHeight(&_fontInfo, fontSize);

    auto cx1 = 0;
    auto cy1 = 0;
    auto cx2 = 0;
    auto cy2 = 0;

    stbtt_GetCodepointBitmapBox(&_fontInfo, int(key.codepoint), scale, scale, &cx1, &cy1, &cx2, &cy2);

    constexpr auto padding = 5;

    const auto bitmapWidth  = cx2 - cx1;
    const auto bitmapHeight = cy2 - cy1;

    auto maybeInsertedRect =
        _pages[*_currentPageIndex].pack.insert(bitmapWidth + padding, bitmapHeight + padding);

    if (!maybeInsertedRect)
    {
        appendNewPage();
        maybeInsertedRect =
            _pages[*_currentPageIndex].pack.insert(bitmapWidth + padding, bitmapHeight + padding);
    }

    if (!maybeInsertedRect)
    {
        // Ok, it failed for real. The font size might just be too large (for now).
        throw Error(formatString(
            "Failed to rasterize a font glyph. The font size ({}) might be too large.",
            fontSize));
    }

    auto insertedRect = *maybeInsertedRect;
    insertedRect.width -= padding;
    insertedRect.height -= padding;

    if (bitmapWidth > 0 && bitmapHeight > 0)
    {
        auto&      page       = _pages[*_currentPageIndex];
        const auto xInPage    = insertedRect.x;
        const auto yInPage    = insertedRect.y;
        const auto pixelCount = bitmapWidth * bitmapHeight;

        _glyphBufferU8.resizeIfGreater(pixelCount);
        _glyphBufferRGBA.resizeIfGreater(pixelCount);

        stbtt_MakeCodepointBitmap(
            &_fontInfo,
            _glyphBufferU8.data(),
            bitmapWidth,
            bitmapHeight,
            bitmapWidth,
            scale,
            scale,
            narrow<int>(key.codepoint));

        _glyphBufferRGBA.clear();

        // Update the RGBA buffer.
        {
            const auto* src = _glyphBufferU8.data();

            for (auto i = 0; i < pixelCount; ++i)
            {
                _glyphBufferRGBA.add(R8G8B8A8{255, 255, 255, *src});
                ++src;
            }
        }

        page.atlas.updateData(xInPage, yInPage, bitmapWidth, bitmapHeight, _glyphBufferRGBA.data(), true);
    }

    auto insertedPtr = _rasterizedGlyphs.add(
        key,
        RasterizedGlyph{
            .uvRect    = insertedRect.toRectf(),
            .pageIndex = *_currentPageIndex,
        });

    assume(insertedPtr);

    return insertedPtr->second;
}

void Font::Impl::appendNewPage()
{
    const auto caps = Painter::Impl::instance()->capabilities();

    const auto width  = min(512u, caps.maxImageExtent);
    const auto height = width;

    auto page = FontPage{
        .width  = width,
        .height = height,
        .pack   = BinPack(width, height),
        .atlas  = Image(ImageUsage::Updatable, width, height, ImageFormat::R8G8B8A8UNorm, nullptr),
    };

    const auto imageLabel = formatString("{}_Page{}", assetName(), _pages.size());
    page.atlas.setDebuggingLabel(imageLabel);

    _pages.add(std::move(page));

    _currentPageIndex = _pages.size() - 1;
}
} // namespace Polly
