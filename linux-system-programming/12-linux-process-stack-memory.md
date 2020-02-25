# Linux Processes Stack Memory

## Linux Process Stack Memory Management

1. Each process has it's own `virtual memory` address space.

2. __Linux Process Memory Map__

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

    1. __Caller__ - Push the `procedure arguments` in revers order onto the new callee stack frame.

    2. __Caller__ - Push the address of the next instruction as the `return address` onto the new callee stack frame. This is so it can reset `ebp` when the call is finished.

    3. __Caller__ - Set the `PC` to the first instruction of the `callee`.

    4. __Callee__ - Push the caller's stackframe `base pointer` onto the callee stack frame. This is so it can be reset `eip` when the call is finished.

    5. __Callee__ - Push the `local variables` onto the callee stack frame.

    6. __Callee__ - Begin execution.

2. Each time a `process` completes and `returns` from a procedure call the `stack frame` is _destroyed_ (`popped`) off the `stack memory`.

    1. __Callee__ - Set the `return value address` of the callee in the `eax` register.

    2. __Callee__ - Increase the `SP` by the amount used by the stackframe. Increasing the `SP` ops the stacks as it grows upwards.

    3. __Callee__ - Restore `ebp` to point to the callers stackframe and pop the previous frames base pointer from the stack.

    4. __Callee__ - Set `eip` to the return address saved in the callee's stackframe and pop the return address from the stack.

    5. __Caller__ - Pop all the `procedure arguments` it passed to the callee stackframe.

    6. __Caller__ - Read the value stored in `eax` return register and resume executing from `eip`.

3. The `execution of procedure call` is carried out using various processor registers:

    1. `eip` : __Instruction Pointer Register__ - Stores the address of the next instruction to be executed.
    
    2. `ebp` : __Base Pointer Register__ - Stores the address of the frame from which offsets are used to access stack frame data. 

        * `Memory` is accessed as an __offset__ from this addresses. e.g. procedure `arguments` and `local variables`.
    
    3. `esp` : __Stack Pointer Register__ - Store the address of the `top` of the stack (lowest VM address).

        * So we know where to add the next stack frame if one need to be created.
    
    4. `eax` : __Return Result Register__ - Stores the address of the last result returned by a procedure call.

---

## Stack Memory

    ```
    High VM Address Space
    +--------------------------+
    |  Procedure Argument 2    |    * The parameter arguments are pushed onto the stack frame in reverse order.
    +--------------------------+
    |  Procedure Argument 1    |
    +--------------------------+
    |  Callee IP               |    * The stored calling `instruction pointer` at point of invocation.
    +--------------------------+
    |  Callee Base Pointer     |    * The stored calling stack frame `base pointer`.
    +--------------------------+
    |  Local Variable 2        |    * The local variables are pushed onto the stack frame in reverse order.
    +--------------------------+
    |  Local Variable 1        |
    +--------------------------+
    ```

1. `Stack Corruptions` occur when any part of the unallocated `virtual address space` is used. A `segmentation fault` is created.

2. The `ebp` `base pointer` register is used as the offset to find the address of `procedure arguments` and `local variables`.

    1. `procedure argument` addresses are indexed by __adding__  (WORD_SIZE + 1) * n bytes increments to the value of the `ebp` register.

        * e.g. __ebp + WORD_SIZE__ is the address of the stored callers instruction pointer.

    2. `local variables` addresses are indexed by __subtracting__  WORD_SIZE * n bytes increments to the value of the `ebp` register.
