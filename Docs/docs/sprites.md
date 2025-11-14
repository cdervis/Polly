---
icon: material/image-outline
---

# Sprites

Drawing sprites is the primary task in a 2D game's visual presentation.

In Polly, `#!cpp Painter::drawSprite()` responsible for this.

There are two versions of `#!cpp drawSprite()` available:

1. `#!cpp void drawSprite(Image image, Vec2 position, Color color = white)`
2. `#!cpp void drawSprite(Sprite sprite)`

Version 1 is a convenience method for version 2; they both perform the same action. We will focus on version 2, which takes a single `Sprite` parameter and therefore provides more options.

```cpp title="Definition of the Sprite structure"
struct Sprite
{
    Image            image;
    Rectangle        dstRect;
    Maybe<Rectangle> srcRect;
    Color            color;
    Radians          rotation;
    Vector2          origin;
    Vector2          scale;
    SpriteFlip       flip;
};
```

!!! note
    All coordinates and sizes in `Sprite` are expressed in **pixels**.

```cpp title="Drawing a sprite"
struct MyGame : Game
{
    Image myImage = Image("myImage.png");

    void draw(Painter painter) override
    {
        // Using the simple version:
        painter.drawSprite(myImage, Vec2(250, 150), blue);

        // Using the extended version:
        painter.drawSprite(Sprite {
            .image   = myImage,
            // Draw at {200, 200} with size {128, 128}
            .dstRect = Rectangle(200, 200, 128, 128),
            .color   = red,
            .flip    = SpriteFlip::Horizontally,
        });
    }
}
```

Which version of `#!cpp drawSprite()` you choose is up to your convenience.

## Destination and source

A sprite has two special properties called `dstRect` and `srcRect`.
The destination specifies the sprite's area within the canvas (window).

A destination of `#!cpp {200, 250, 128, 64}` means that the sprite is drawn with its top-left corner at position `#!cpp {200, 250}`, of size `#!cpp {128, 64}`.

This means that its right border will be at X-coordinate `#!cpp 200 + 128 = 328`, while its bottom border will be at Y-coordinate `#!cpp 250 + 64 = 314`.

The destination rectangle is often used to stretch or shrink (scale) a sprite, disregarding its image size. For example, when you draw a sprite using `#!cpp drawSprite(image, Vec2(200, 200))`, the function calculates a destination rectangle for you, which ultimately is `#!cpp {pos.x, pos.y, imageWidth, imageHeight}`.

The source rectangle on the other hand refers to coordinates within the sprite's image. To illustrate this, let's take a look at the following image:

![img](../assets/images/sprite-src-rect.webp){.align-center}

The green rectangle represents the source rectangle.
In this case, `#!cpp {75, 75, 150, 150}`.

The source rectangle is often used to implement sprite sheets and sprite animations. This allows multiple images to be stored in a single large image (atlas) and to still be drawn independently.

Such a technique is necessary when your game has hundreds or thousands of sprites in order to minimize texture changes and draw
operations in the internal graphics API, which are an expensive operation.

One example is Polly's text rendering, which makes use of source rectangles. Since all characters are stored in a large image, each character in a string is drawn as a sprite that references its region in that image.
