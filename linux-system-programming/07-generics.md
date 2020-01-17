# Generics

## Introduction

1. `Libraries` should be `application agnostic`.

2. `Libraries` should be able to perform `application specific operation` in a `generic` way. 

    * e.g. A list library might want to provide a `sort` generic operation.

---

## Generic Data

1. `Generic data` can be referenced using a `void *` pointer type.

    ```C
    typedef struct dll_node {
        void *data;
        struct dll_node *left;
        struct dll_node *right;
    } dll_node_t;
    ```

## Function Pointers (Callbacks)

1. `Function pointer callback` can allow library to perform operations on the unknown data.

    1. `Generic logic` is written as function in the library that invokes application specific `function pointers`.

    2. `Data specific` functions are developed and `registered` with the `library` to handle different types of data. 
    