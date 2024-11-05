# "Affractors"

Currently just a template for me to potentially create SDL applications

This is also my first time using SDL, so it should hopefully help me get more familiar with that.

### THE GOAL

I want to eventually use this to visualize "chaos-method" attractor fractals in 3D.
Acerola has a fantastic [video on this topic](https://youtu.be/1L-x_DH3Uvg?si=_sc4_6f4LQm7wIW0) that has inspired this project.


### Dependencies
`clang`:
*   The `build.sh` script uses clang to compile and link the c++ code.
*   There is also a `.clangd` file which should help the clang LLVM LSP resolve include directories

`SDL3`:
*   Currently, users would need to have [SDL3](https://github.com/libsdl-org/SDL/releases/tag/preview-3.1.6) installed under `/usr/local`.
*   This is actually undesireable as I'd rather have users be able to download and build this out of the box, so this will be changing in the future, as I develop my linux build system more (recently switched from windows)


## DOWNLOAD + BUILDING

**_NOTE:_** Again! This is assuming you have the dependencies listed above installed

Clone the repository:
```bash
$ git clone git@github.com:MiniFalafel/Affractors.git
```

Run the build script from inside the project directory:
```bash
$ cd Affractors
$ ./build.sh
```
