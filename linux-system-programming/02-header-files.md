# Header Files and Preprocessing

## Introduction

1. `Header files` allow C programs to be `designed` and `organised`.

2. `Header files` are **non-compilation units**.

   - They are parsed to extract information so can contain errors.

   - They make is easier for the compiler to function.

3. `Header files` can be `included` and imported into `source files.

> A `header file` are like an `interface` rhar declares what a `source file` can do without exposing the implementation.

---

## Header file Inclusion

1. Recursive Text Substation - Expand any `macro` definitions.

2. Replace `#include<x.h>` statements with the _contents_ of `x.h`.

3. Recursively replaces and new `#include<x.h>`statements introduced by Step 2.

---

## C/C++ - Compilation Definition Rules

1. **Define and Use** - Define `structure definitions` before they are used.

2. **Declare and Use** - Define `function prototypes` before they are used.

---

## Library File Organisation

1. Code is organised into `header` files and `source` files.

2. `Header files` should contain _anything that needs to be exposed to other source files_.

   - structure definitions, constants, enumerations, Macros, function declarations, static inline functions.

3. `Source files` should contain _anything that should not be exposed to other source files_.

   - Function definitions, and, anything else that should be _private_ and not shared.

   - `Source files` inherited all the information they include from their header files.

---

## Text Substitution (Source file Preprocessing)

1. `Text Substitution` happens in `source files` by the compiler **before** being compiled.

2. `Text Substitution` is also known as `preprocessing`.

3. `C/C++` has several `preprocessing` directives:

   1. `#include` - Recursively, replace the contents of the targeted header file in this file.

   2. `#define` - Replace all occurrences of the defined `marker` with the specified `string`.

      - e.g. `square(x) (x*x)`

4. `Preprocessing` transformation can be performed using `gcc`:

   - `gcc -E aap.c -o app.i`

---

## Duplicate Header File Inclusion

1. **Duplicate Inclusion Errors**

   1. `Text Substitution` is resolved recursively.

   2. If the compiled source files transitively `#include` the same header file, any `#define` statements will be substituted multiple times.

   3. This will cause a compile error.

   4. Additional control directives can be used to control the substitution.

2. **Best Practice**

   1. To avoid `duplicated definitions errors`, the best practice for a header file `Header.h` is to always include protective directives:

   ```C
   #ifndef __Header__
   #define __Header__

   #include x1.h
   #include x.h
   #define PI 3.2141592
   #define min(a,b) ( a > b ? a : b)

   #endif

   ...
   ```

   > If '**Header**' is not defined; then define **Header** and subsitute it's contents; otherwise it has already been done so do nothing.
