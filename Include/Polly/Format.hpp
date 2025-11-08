// Copyright (C) 2023-2024 Cem Dervis
// This file is part of Polly, a minimalistic 2D C++ game framework.
// For conditions of distribution and use, see copyright notice in LICENSE, or https://polly2d.org.

#pragma once

#include "Polly/Maybe.hpp"
#include "Polly/String.hpp"
#include "Polly/StringView.hpp"
#include "Polly/ToString.hpp"

namespace Polly
{
namespace Details
{
template<typename T>
static void formatHelper(String& buffer, StringView& str, const T& value)
{
    const auto openBracket = str.find('{');
    if (!openBracket)
    {
        return;
    }

    const auto closeBracket = str.find('}', *openBracket + 1);
    if (!closeBracket)
    {
        return;
    }

    buffer += str.substring(0, *openBracket);
    buffer += Polly::toString(value);

    str = str.substring(*closeBracket + 1);
}
} // namespace Details

/// Formats a string using an arbitrary number of arguments.
///
/// Example:
///
/// auto str = formatString("Hello {}! {}, {}", "World", 10, Vec2(1, 2));
/// -> "Hello World! 10, [x=1; y=2]"
///
/// Currently, the only supported format specifier is '{}'.
template<typename... Args>
[[nodiscard]]
static String formatString(StringView fmt, Args&&... args)
{
    auto result = String();
    (Details::formatHelper(result, fmt, std::forward<Args>(args)), ...);
    result += fmt;
    return result;
}
} // namespace Polly
