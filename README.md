# ProteaEngine ![License](https://img.shields.io/badge/license-Apache%202.0-blue)

![ProteaEngine](/Resources/Documentation/Protea_Engine_Logo_2160.png?raw=true "ProteaEngine")

ProteaEngine is an early-stage rendering engine for Windows, built as a learning tool for game engine development.
Currently not much is implemented, however this entire project serves as a hands-on educational experience to understand
the fundamentals of engine architecture, graphics programming, and system design.

This project draws inspiration from TheCherno's engine development series found at thecherno.com/engine, adapted and
expanded upon as part of my personal development journey in understanding how modern game engines work from the ground
up.

## Getting Started

ProteaEngine has not been tested on many development environments - Currently the only supported build is for Windows.

### Prerequisites

- CMake
- C++ Compiler (Clang or MSVC recommended)
- Git

## Building ProteaEngine

### Clone the repository:

```
git clone https://github.com/PegasusXing/ProteaEngine.git
cd ProteaEngine
```

### Build using the build script:

```
.\build.bat
```

The script will prompt you to choose your compiler toolchain. The build system uses Ninja as the default generator,
though Make has also been tested and works.

***NOTE:*** GCC build currently fails due to C++20 being used. A solution is in the works.

## Development Environment Setup

### CLion:

- Open the cloned project in CLion
- The CMake configuration should be detected automatically
- Tested and working with both Clang and MSVC toolchains
- GCC is currently unstable and not recommended

### Visual Studio 2019/2022:

- Open cloned project in Visual Studio
- All CMake targets should be loaded correctly
- The engine builds and runs successfully

## Known Issues

- Some filepath issues regarding image sources are currently being resolved
- GCC toolchain support is currently unstable

## Next Steps

Once built successfully, you can run the application and begin exploring the engine architecture. Check the project
structure and existing code to understand the current implementation status.