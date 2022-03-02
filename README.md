[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

<p align="center">
  <h1 align="center">A C++ project</h1>

  <p align="center">
    My project.
  </p>

# Setup

This section describes the directory structure of the project and the build
system, you can delete it after everything is working.

* The main app is located at `src/project_name`.
* Under `src` there is a folder `libs`, made to store parts of the app that
might be written as libraries.
* Unit tests are written using [Catch2](https://github.com/catchorg/Catch2)
v2.x, and are located under `tests`.
* External libraries that should be kept available with the source code are
located under `external`. GLFW is included as an example.
* The `build` folder is divided into `debug` and `release`. Both versions can
coexist.
* The `docs` folder stores the project's documentation.
* A `Makefile` is provided for convenience. It contains targets to compile
(debug and release), clean, run the main executable and the tests. The
relevant `CMake` compilation options can be defined in this file, including
the ones for external libraries.
* I use [neovim](https://neovim.io/) as a text editor and
[coc-clangd](https://github.com/clangd/coc-clangd) as a language server. The
file `compile_commands.json` is used by [clangd](https://clangd.llvm.org/)
to provide intelliSense capabilities. It is generated automatically by the
`Makefile` (`CMake` option `CMAKE_EXPORT_COMPILE_COMMANDS=1`) during
compilation and copied to the program's root directory.
* The project is built using [CMake](https://cmake.org/). See the
`CMakeLists.txt` files for more details.

```bash
├── build
│  ├── debug
│  └── release
├── CMakeLists.txt
├── compile_commands.json
├── docs
│  └── README.md
├── external
│  └── glfw
├── LICENSE.txt
├── Makefile
├── README.md
├── src
│  ├── libs
│  │  └── lib1
│  │     ├── CMakeLists.txt
│  │     └── lib1
│  └── project_name
│     ├── CMakeLists.txt
│     ├── hello.cpp
│     ├── hello.hpp
│     └── main.cpp
└── tests
   ├── build
   ├── CMakeLists.txt
   ├── data
   │  └── README.md
   ├── main.cpp
   ├── test-1.cpp
   └── test-2.cpp
```


# README STARTS HERE

## About The Project

Describe the project here.

### Prerequisites / Dependencies

List here the libraries/frameworks used to build the project. Refer to the
installation pages.

### Installation

Describe how to compile/install the project.

### Usage

Describe how to use the software.

### Contributing

Information for possible future contributors.

## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

[license-shield]: https://img.shields.io/github/license/lbteixeira/code-starters?style=for-the-badge
[license-url]: https://github.com/lbteixeira/code-starters/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/lucasbrederteixeira
