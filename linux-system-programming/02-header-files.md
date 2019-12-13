# Header Files and Preprocessing

## Introduction

1. `Header files` allow C programs to be `designed` and `organised`.

2. `Header files` are __non-compilation units__.

    * They are pasrsed to ectract information so can contain errors.

    * They make is easier for the compiler to funciton.

3.  `Header files` can be `included` and imported into `source files.

> A `header file` are like an `interface` rhar declares what a `source file` can do without exposing the implementation.

---

## Header file Inclusion

1. Recursive Text Substition - Expand any `macro` definitions.

2. Replace `#include<x.h>` statements with the _contents_ of `x.h`.

3. Recursively replaces and new `#include<x.h>`statements introduced by Step 2.

---

## C/C++ - Compilation Definition Rules

1. __Define and Use__ - Define `structure definitions` before they are used.

2. __Declare and Use__ - Define `function prototypes` before they are used.

---

## Library File Organisation

1. Code is orgnaised into `header` files and `source` files.

2. `Header files` should contain _anything that needs to be exposed to other source files_.

    * structure definitions, constants, enumerations, Macros, function declarations, static inline functions.

3. `Source files` should contain _anything that should not be exposed to other source files_.

    * function definitions, and, anything else that should be _private_ and not shared.

    * `Source files` inherited all the information they include from their header files.

---

## Source file Preprocessing (Text Substitution)

1. `Preprocessing` happens in `source files` by the compiler __before__ being compiled.

2. `Preprocessing` is also known as preprocessing.

3. `C/C++` has two `preprocessing` directives:

    1. `#include` - Recursively, replace the contents fo the targeted header file in this file.

    2. `#define` - Replace all occurrences of the defined `marker` with the specified `string`.

        * e.g. `square(x) (x*x)`

4. `Preprocessing` transformation can be performed using `gcc`:

    * `gcc -E aap.c -o app.i


