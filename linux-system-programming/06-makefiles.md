# Makefiles

## Introduction

* `Makefiles` are a tool to help `build` large programs. Specifically, C / C++ programs.

* `Makefiles` help manage the `dependencies` between `source files`.

* `Makefiles` work on the concept of a `dependency tree`.

* `Makefiles` support incremental processing.

    * Changes to `leaves` in the tree only affect dependent `ancestors` where the root is the final `output`.

* `Makefiles` are made of `rules`. Each rule defines:

    1. __Target__ - The `output` to create (object file, library, executable, etc)

        * `PHONY Targets` can also be specified by any string. e.g. `TARGET` or `clean`.

    2. __Dependencies__ - The `raw inputs` required to create the `target`.

    3. __Actions__ - The commands to execute to create the `target` from the `dependencies`.

    * `MakeFile Rule Example` 

        ```Make
        common_math.o: common_math/common_math.c
            gcc -c -I common_math common_math/common_math.c -o common_math.common_math.o
        ```

        * NB: `-I` <path> specifies the location of the `header files`.
    
    > NB: Remember to include '*.so' dynamic libraries if they are imported by any header files.

* `Makefile rules` are executed using a `depth first search` based on the `dependencies` of the initial `target`.

---

## Functions of a Makefile

1. Compilation of `source files` and creation of `object files`.

2. Linking `libraries` and `object files`.

3. Creating `static libraries` and `dynamic libraries`.

4. Creating `executables`.

5. Installing `libraries` and `executables`.

6. Update `dependencies`.

---

## Usage

1. __Run__ - `make [rule_name]`

    * There can only be one `Makefile` in a directory.

