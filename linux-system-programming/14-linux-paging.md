# Paging

## Introduction

* `Paging` gives the _illusion_ to `each process in execution` that it has `full amount of physical memory available`.

    * e.g. 32 bit system 2^32 bytes (4GB) - All process think they have 4GB memory, even though there are multiples processes.

* `Paging` allows processes to store information in `non-contiguous blocks of memory` whilst providing the _illusion_ they are `contiguous`.

* `Paging` allows multiple processes to use the same `physical memory locations` over time.

* `Paging` is implemented by special hardware called the `MMU (Memory Management Unit)`.

---

## Architecture, Buses, and, Byte Addressable Memory

* The `architecture` type `32` or `64` bits determines the maximum size of the `byte addressable memory`.

* `Byte Addressable Memory` is memory where every `byte has an address`, and the addresses are contiguous. 

    * Logical boolean operations are used to manipulate the bytes at the bit level.

    * This can be `physical` or `virtual` memory.

* `Buses` are `physical connections` (one for each bit in the architecture) that are used to exchange information between hardware components.

    * Setting a `high voltage` on a bus connection denotes a binary `1` and a `low voltage` denotes a `0`.

    * The `MMU` converts the `logical address` to a `physical address`.

    * The `address bus` selects the physical memory address to access. 

    * The `data bus` then exchanges the the data at that address. NB: There is one bus line for each byte (4 for a 32 bit architecture, 8 for a 64 bit architecture).

* A `CPU` generates `virtual memory addresses` during execution.

    * The `virtual memory addresses` are __mapped__ to `physical memory addresses` by the `MMU`.

---

## Physical Pages and Frames

* `Virtual Memory Addresses` are translated to `Physical Memory Addresses` via `MMU Paging`.











