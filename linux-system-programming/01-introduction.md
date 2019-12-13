# Basic C Program Structure and Compilation

## Introduction

1. `C` is a high-level programming language that allows programs to be represented with respect to the underlying physical hardware.

2. `Compilation` is the process of taking `source code` and using a `compiler` to produce executable `machine instructions`.

3. For the `C` language on a `linux` system: 

    1. The `compilation step` produces an `object file` containing the instructions to execute.

    2. The `link step` produces an `excutable file` from a set of `object files`.

4. `Libraries` are object files containing functionality that wants to be shared `between applications`.

    * e.g. A `collection datastructure` library.

5. `C` programs are typically structured using:

    1. `Header Files` - Macros, constants, types, public function definitions. `*.h`.

    2. `Program Files` - Containing implementations of the public interfaces. `*.c`.

6. `#include` directives are used to describe header file`dependencies`.

7. To create an `executable` file all the required source file must be `compiled` and `linked`.

    1. One of the source files __must__ declare the `main` method entry point into the `executable`.

---

## `gcc` - Basic cCmpilation and Linking

1. Basic `gcc` compilation: `gcc -c source.c -o compilied.o`

2. You should always be able to compile a source file independently.

    1. Even when `app.c` depends on `lib.c` the following should compile:

    ```bash
    gcc -g -c app.c -o app.o
    gcc -g -c lib.c -o lib.o
    gcc -g  app.o lib.o -o app
    ./app
    ```

## `gcc` basic options

* `-c` - Compiles source files without linking.
* `-o` - Writes the build output to an output file.
* `-g` - Generates debug information to be used by GDB debugger. Levelled.
* `-O` - Set the compiler's optimization level. Levelled.
* `-I` - Adds include directory of header files. `-Idirpath`.
* `-l` - Use and links with a specific library file. `-l$filepath`.
* `-L` - Looks in directory for library files. `-L$dirpath`.
* `-D` - Defines a macro to be used by the preprocessor. `-Dname=definition`
* `-E` - Apply the preprocessor to performa text substitution without compiling.

