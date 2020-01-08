# Preprocessing Directives

## Introduction

* `Directive` - A bit of code that is handled by the preprocessor to manage substitution behaviour before compilation. 

    * Exist on a single line.

    * `\` - Can be used to cosmetically split directives. 

*  `Macro` - A token and a bit of code. The token gets expanded into the code by the preprocessor.

    * Created by `#define` directive.

---

## Directives

1. `#include` The preprocessor substitutes (cut and paste) the code of given system file into current.

    1. `#include <file>` - Searches standard and specified system directories.

    2. `#include "file"` -  current and then system directories.

    3. `#include file` - A computed include.

2. `#define` - The preprocessor substitutes occurrence of the token with the defined a constant `value` or `function macro`.

    1. `#define Object` - A segment of code which is replaced by the value e.g. Constant.

    2. `#define Function` - A segment of code which is replaced by the value e.g. Function.

3. `#undef` - Cancel an existing checks if macro is defined by #define 

4. `#ifdef, #endif` - Check if macro is defined by #define.

5. `#ifndef, #endif` - Check if macro is NOT defined by #define.

6. `#if, #elif, #else, #endif`- Evaluates the expression or condition and executes the selected code statements.

7. `#error` - Issue a fatal errors and halt compilation.

8. `#pragma` - Provide additional metadata to the compiler.


