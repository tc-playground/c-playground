# Libraries and Linking

1. Object files (`*.o`) are compile from source files (`*.h` and `*.c`).

2. A `library` is a collection of related object files.

    * By convention the name of the library should be prefixed by `lib`.

3. There are two types of `C/C++ library` on the linux platform: `Static` and `Dynamic`:

    1. __Static Libraries__ - (`lib*.a`)

        1. __Create__  - Compile with `gcc`, then archive into library with `ar`:

            ```bash
            gcc -c <libname>.c -o <libname>.o
            gcc -c util.c -o util.o
            ar as lib<libname>.a <libname>.o util.o 
            ```

        2. __Linking__ - A `static library` can be `linked` to new object files to create an `executable`:

            * `-L` can be used to define the `path` to the library, and `-l` can specify the name:

                ```bash
                gcc -c app.c -o app.o
                gcc app.o -o app -L . -l<libname>
                ```

            * `libname` is the name of the library without the `lib` prefix convention: e.g. `libdll` -> `dll`.            

    2. __Dynamic Libraries__  - (`lib*.so`)

        1. __Create__ - Compile with `gcc` and `-fPIC` flag, then link with `gcc` and the `-shared` flag:

            ```bash
            gcc -c -fPIC <libname>.c -o <libname>.o
            gcc -c -fPIC util.c -o util.o
            gcc <libname>.o util.o -shared lib<libname>.so
            ```

            * __PIC__ - `Position Independent Code` (generate position independent assembly code during compilation)

        2. __Linking__ - A `dynamic library` can be `linked` to new object files to create an `executable`:

            * The dynamic library must be copied to a `system library directory` and the `library database` updated:

                ```bash
                cp lib<libname>.so /usr/lib && sudo ldconfig
                gcc -c app.c -o app.o
                gcc app.o -o app -L . -l<libname>
                ```    

            * `libname` is the name of the library without the `lib` prefix convention: e.g. `libdll` -> `dll`.

            * `/usr/lib` is a directory for shared user libraries.

            * `ldconfig` is a command that can be used to update the OS library path database.


> __Compilation__ - Converts `source files` to `object files`.

> __Linking__ - Converts several `object files` and `libraries` into an `executable`.
