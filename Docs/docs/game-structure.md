---
icon: octicons/package-24
---

# Game Structure

While Polly is very flexible, there is a certain structure that's expected to be maintained.
The following shows the standard folder structure for a game:

```cpp
MyGame/
├── Assets/             // The game's assets
│   ├── MyImage.png
│   ├── MyFont.ttf
│   └── MySound.wav
├── Src/                // The game's C++ code
│   ├── Game.hpp
│   ├── Game.cpp
│   ├── SomeModule.hpp
│   └── ...
├── Misc/               // Misc files such as icons, metadata
│   ├── Icon.png
│   └── ...
└── CMakeLists.txt      // The root CMake script
```

## Assets

All game assets are in the `Assets` folder and are **automatically processed at build time**.
Adding, removing and changing an asset will be picked up by the build system and update the game's archive automatically.

Asset types such as `Image`, `Font` and `Sound` is loadable directly using its constructor that takes a single string argument. When an asset fails to load, for example due to a non-existent file or system error, an `Error` is thrown.

```cpp title="Loading assets in C++"
auto image  = Image("MyImage.png");
auto font   = Font("MyFont.ttf");
auto sound  = Sound("MySound.wav");
auto sound2 = Sound("DoesNotExist.mp3"); // throws an Error
```

Loaded assets are cached, which means that when you load a specific asset multiple times,
it always refers to the same object in memory. All asset types are reference-counted objects.
See [C++ API Design](../cpp.md) for details.

The cache itself won't hold a reference to this asset, but will observe its lifetime. You can't unload an asset explictly; this will happen automatically. When a loaded asset reaches a reference count of zero, it's destroyed and unloaded from the cache.

The next time this asset is loaded, it will be loaded again.

## Asset Bundling

The assets of a game are processed at build time, before the game is built. This ensures multiple things:

- The game's assets are verified for validity
- Assets can be optimized and transformed to a more efficient data format
- All assets can be packed into an efficient binary archive

Asset bundling is part of Polly and runs automatically; you don't have to configure anything. A game's final assets are stored in a `data.pla` file.

## Source Code

The game's source code is in the `Src` folder and is automatically scanned by CMake.
This means that you can add, remove and rename source files without having to touch the game's CMake script.
When building the game, file changes are picked up automatically prior to building them.

The source files are expected to be C/C++ files (`.h`, `.hpp`, `.c`, `.cpp`).
