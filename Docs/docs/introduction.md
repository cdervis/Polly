---
title: Introduction
icon: lucide/house
---

<h1 class="main-title" style="text-align: center">Polly</h1>

<p class="sub-title center-text" style="font-size: 120%">Minimalistic 2D C++ Game Framework</p>

![cover](assets/images/logo256.png){ width=130 .align-center .margin-top-bottom-medium }

<p class="center-text">
Polly is a framework that makes it easy to get started with C++ 2D game development using a clean, modern API, for beginners and experts alike. It provides every audiovisual aspect necessary to comfortably make a 2D game using a code-only approach.
</p>

<!--
<div class="centering-container">
    <a class="docmd-button"  href="#getting-started">Get Started</a>
</div>
-->

![Polly Demo Browser](assets/images/cover-1.webp){ .align-center width=800 }

## Who is this for?

Polly is designed to be a "bring your own tools" game framework, not an engine.
It's for those who want to develop a 2D game using a flexible and portable high-performance
language without any of the overhead that comes with a classic game engine.

By leveraging modern C++ and a custom, simplified standard library, it provides an easy to use
API that just gets out of your way. Polly produces minimal executables that run without any
additional runtime or garbage collector.

There is no map editor, no sprite editor and no strict entity architecture. Just your code and idea.

## Do I need to know C++ and CMake?

Ideally, you should at least have some beginner-level experience with (modern) C++. This will help you follow
the documentation more easily. On the other hand, you do **not** need to write any CMake in order to make a game.

Polly takes care of the majority of the CMake code. You simply need an editor or IDE that understands CMake (see [below](#getting-started)).

---

??? note "Platform Support"

    Polly is able to run on the following platforms:

    - Windows x64 & ARM64
    - Linux x64 & ARM64 (Ubuntu, Fedora, Debian)
    - Linux RISC-V (tested with StarFive VisionFive board, Debian)
    - macOS 13+ (released in 2022)
    - iOS 16+ (released in 2022)
    - Android 8.0+ (all ABIs)[^1]
    - Web[^1]

    [^1]: Android and Web is technically supported, but work is in progress to make the out-of-the-box experience more polished.

??? note "Compiler Support"

    Polly is tested and can be built with the following toolchains:

    - Visual Studio 2022 and later (MSVC)
    - GCC 11.4 and later
    - Clang 17 and later
    - Xcode 13 and later

!!! note
    Please note that the documentation is currently a work in progress. Some pages might be incomplete, have outdated information or are just placeholders until they're written.

## Getting Started

If you're on Windows, [:material-microsoft-visual-studio: Visual Studio](https://visualstudio.com/) or [:simple-clion: CLion](https://www.jetbrains.com/clion/) is recommended, whichever you prefer.
Visual Studio Community is free for individual developers and can be used to develop free or paid games. CLion is free for non-commercial projects and works on Linux and macOS as well.

Another C++ IDE is  [:simple-qt: Qt Creator](https://www.qt.io/offline-installers), which is free, open source and cross-platform.

- If you use [Homebrew](https://github.com/Homebrew/brew/releases), you can install Qt Creator easily using `#!sh brew install qt-creator`.
- On Linux with apt, you can use `#!sh apt install qtcreator`.
- It's also available as a [Flatpak](https://flathub.org/en/apps/io.qt.QtCreator).

### Install Dependencies

=== ":material-microsoft-windows: Windows"

    Please ensure that [Git](https://git-scm.com/downloads/win) and [Python 3](https://www.python.org/downloads/windows/) are installed.

=== ":material-apple: macOS"

    Please ensure that [Homebrew](https://github.com/Homebrew/brew/releases) is installed. Then install [Xcode](https://developer.apple.com/xcode/):
   
    ```sh
    xcode-select --install
    ```
   
    Then install Git and CMake:
   
    ```sh
    brew install git cmake
    ```

=== ":material-linux: Linux"

    On Linux, development libraries are required, including for X11, Wayland and ALSA.
   
    **Ubuntu and similar (apt)**
   
    ```sh
    sudo apt install build-essential git make binutils pkg-config cmake ninja-build clang-format \
                     gnome-desktop-testing libasound2-dev libpulse-dev \
                     libaudio-dev libjack-dev libsndio-dev libx11-dev libxext-dev \
                     libxrandr-dev libxcursor-dev libxfixes-dev libxi-dev libxss-dev libxtst-dev \
                     libxkbcommon-dev libdrm-dev libgbm-dev libgl1-mesa-dev libgles2-mesa-dev \
                     libegl1-mesa-dev libdbus-1-dev libibus-1.0-dev libudev-dev
    ```
   
    **Fedora and similar (dnf)**
   
    ```sh
    sudo dnf install gcc git-core make cmake ninja-build gcc-c++ pkg-config clang-tools-extra \
                     alsa-lib-devel pulseaudio-libs-devel nas-devel pipewire-devel \
                     libX11-devel libXext-devel libXrandr-devel libXcursor-devel libXfixes-devel \
                     libXi-devel libXScrnSaver-devel dbus-devel ibus-devel \
                     systemd-devel mesa-libGL-devel libxkbcommon-devel mesa-libGLES-devel \
                     mesa-libEGL-devel vulkan-devel wayland-devel wayland-protocols-devel \
                     libdrm-devel mesa-libgbm-devel libdecor-devel \
                     pipewire-jack-audio-connection-kit-devel
    ```

    If you have issues with installing some packages, or see some missing, feel free to [report them](https://github.com/cdervis/Polly/issues).
    
---

### Next Steps

1. 	**Download and unpack the [Game Template](https://github.com/cdervis/Polly/releases/download/v0.9.4/GameTemplate.zip)**

2. 	Open the Game Template in your preferred IDE.

    === ":material-microsoft-visual-studio: With Visual Studio"
    
        ![Opening a CMake project with Visual Studio](assets/images/vs-open-cmake.webp){.align-center .margin-top-medium width=400}
    
    === ":simple-clion: With CLion"
    
        ![Opening a project with CLion](assets/images/clion-open-cmake.webp){.align-center .margin-top-medium width=400}
    
    === ":simple-qt: With Qt Creator"
    
        ![Opening a project with Qt Creator](assets/images/qt-creator-open-cmake.webp){.align-center .margin-top-medium width=700}
    
    === ":simple-xcode: With Xcode"
    
        You can generate an Xcode project for your game with:
    
        ```sh
        cmake -B build/xcode -G Xcode
        ```
        
        And then open the .xcodeproj file via Finder or command line:
        
        ```sh
        open build/xcode/MyGame.xcodeproj
        ```
    
3. Run the game

---

You should now see the game running:
![Your first game window](assets/images/mygame-first-window.webp)

That's it! We're now ready to see [how a game is structured](game-structure.md).

