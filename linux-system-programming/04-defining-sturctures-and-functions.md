# Defining Structures and Functions

## Introduction

1. C compilers traditionally only parse input file once.

2. This means `structures` and `functions` must be **defined** before they are **used**.

3. The compiler parsers the source file from `top to bottom`.

---

## Declaring and Defining Structure

1. A `structure` must be `defined` before it used:

   ```C
   type struct SomeStruct01_ {
       char data[32];
   } some_struct01_t;

   type struct SomeStruct02_ {
       char data[32];
       some_struct01_t ss1;
   } some_struct02_t;
   ```

   - It can also be imported via an `#include` header file directive.

2. There are two way to define `nested structures`:

   1. __Pointer Based__

      ```c
      struct s1_t {
          char data[32];
          s2_t *s2;
      }
      ```

   2. __Embedded__

      ```c
      struct s1_t {
          char data[32];
          s2_t s2;
      }
      ```

1. A compiler must know the size of a structure (the sum of its fields) **at compile time**.

   1. So `embedded usage` requires the embedded struct is `defined` before it is `used`.

   2. If there is `recursive dependency` between two structures, the size of one of the structures will not be known!

   3. By utilising `pointer based` embedding and using a `forward declaration` this issue can be resolved:

      ```c
      struct s2_t;

      struct s1_t {
          char data[32];
          s2_t *s2;
      }

      struct s2_t {
          char data[32];
          s1_t s1;
      }
      ```

---

## Declaring and Defining Structure

1. A `function` must be `declared` before it is used:

   ```C
   int some_func(int x);   // Declare

   some_func();    // Use / Invoke
   ```

2. `Declare and Use Rule`

   1. Each source file should `declare` the function before it is used.

   2. It can also be imported via a `#include` header file directive.

   3. A `function` must be`defined` in _one and only one source file_:

      ```C
      int some_func(int x);   // Declare

      int some_func(int x) {
          // Func Body
      } // Define (in one source file only)

      some_func();    // Use / Invoke
      ```

      1. There should only be one `definition` of the function in the source files. This will be handled by the `linker`.
