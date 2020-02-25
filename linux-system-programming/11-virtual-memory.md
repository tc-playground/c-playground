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










