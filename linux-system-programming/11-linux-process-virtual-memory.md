# Linux Process Virtual Memory

## Introduction

1. Each Linux `process` has it's own `virtual memory` address space that is mapped to `physical memory` via `page tables`.

---

## Physical Memory

1. `Physical Memory` is the amount of actual memory a system has.

2. The upper bound on `physical memory` a system can have is determined by the `physical address space`  which is determined by `size/width of the address bus`.

3. There `32 bit` and `64 bit` architectures - These denotes the size of the `processor words` and `system buses`.

    1. `32 bit` -> `2^32 1-` -> `4294967295` -> `4 GB`.

    2. `64 bit` -> `2^64 - 1` -> `18446744073709551616` -> `17,179,869,184 GB`.

        * Normally the address bus supports 42/48 bits.

4. `Physical Memory` is organised into `4KB Frames` to make allocation more efficient.

---

## Virtual Memory

1. `Virtual Memory` is an abstraction on top of the actual `physical memory`.

2. `Virtual Memory` is the amount of memory available to a `process`.

3. The size of `Virtual Memory` is _architecure_ and _operating system_ dependent.

    * `Linux Processes` support up to `128 TB`.

4. Each process has it's own `virtual memory address space` that is mapped to `physical memory` via one or more `page tables`.

5. The sum of all the processes `virtual memory` can exceed that of `physical memory`.

6. Different processes can have a `virtual memory address space` that is mapped to the same `physical memory` for `interprocess communication`.

7. Linux programs only know about `virtual memory`. They read and write to `virtual memory addresses`. They know nothing about `physical memory`.

---

## Linux Process Memory Management

1. Each process has it's own `virtual memory` address space.

2. __Linux PRocess Memory Map__

    ```
    High VM Address Space
    +--------------------------+
    |  Commandline Arguments   |    * The command line arguments to the process. FIXED.
    +--------------------------+
    |          Stack           |    * The stack grows down from high VM address to low.
    |            |             |    * The stack is a FIFO.
    |            V             |    * Used to store the dynamic `stack frame` for each procedure invocation in the thread.
    | main()                   |
    |  + f1()                  |
    |    + f2()                |    * Procedure parameters, local variables, base pointer, stack frame pointer, etc.
    |                          |
    +--------------------------+
    |                          |    * The heap grows up from low VM addresses to high.
    |                          |    * Used for dynamically allocated memory via library calls: 'malloc', 'calloc', 'realloc', 'free'.
    |                          |    * Library call implement via system calls: `brk`, `sbrk`.
    |            ^             |
    |            |             |
    |           Heap           |
    +--------------------------+
    | Uninitialised Data (BSS) |    * Global / Static data that has not been initialised. FIXED.
    +--------------------------+
    |    Initialised Data      |    * Global / Static data that has been initialised. FIXED.
    +--------------------------+
    |                          |
    |          Code            |    * Assembler / Machine code instructions. FIXED
    |                          |
    +--------------------------+
    Low VM Address Space
    ```

---

## Linux Process Stack Virtual Memory Management

1. Each time a `process` invokes a procedure call a new `stack frame` is _created_ and (`pushed`) on the `stack memory`.

2. Each time a `process` completes and `returns` from a procedure call the `stack frame` is _destroyed_ (`popped`) off the `stack memory`.

3. The `execution of procedure call` is carried out using various processor registers:

    1. `eip` : __Instruction Pointer Register__ - Stores the address of the next instruction to be executed.
    
    2. `ebp` : __Base Pointer Register__ - Stores the address of the frame from which offsets are used to access stack frame data. 

        * `Memory` is accessed as an __offset__ from this addresses. e.g. procedure `arguments` and `local variables`.
    
    3. `esp` : __Stack Pointer Register__ - Store the address of the `top` of the stack (lowest VM address).

        * So we know where to add the next stack frame if one need to be created.
    
    4. `eax` : __Return Result Register__ - Stores the address of the last result returned by a procedure call.


3. __Stack Frame Memory Layout__

    ```
    High VM Address Space
    +--------------------------+
    |  Procedure Argument 2    |    * The parameter arguments are pushed onto the stack frame in reverse order.
    +--------------------------+
    |  Procedure Argument 1    |
    +--------------------------+
    |  Callee IP               |    * The stored callee `instruction pointer` at point of invocation.
    +--------------------------+
    |  Callee Base Pointer     |    * The stored called stack frame `base pointer`.
    +--------------------------+
    |  Local Variable 2        |    * The local variables are pushed onto the stack frame in reverse order.
    +--------------------------+
    |  Local Variable 1        |
    +--------------------------+
    ```

3. `Stack Corruptions` occur when any part of the unallocated `virtual address space` is used. A `segmentation fault` is created.
