# Linux Processes Stack Memory

## Heap Memory

1. A `Break Pointer` is maintained by the OS for each process and is used to denote `the top of heap memory`. 

    1. Any memory address above the `break pointer` cannot be used by the process. Doing so will cause a `segmentation fault`.

2. The `Standard C Library` __libc__ contains methods for allocating and freeing `heap memory`.

    1. `malloc` - Allocates the specified _amount of memory in bytes_ and returns a pointer to the allocated memory. Also add a `metadata block` and `mod 4 byte padding`.

    2. `calloc` - Performs the same operation as malloc, but, also initialises the allocated memory to 0.  

    3. `free` - Frees the specified memory addressed by the pointer. Uses the `metadata block` to determine how much to free.

3. The `malloc`, `calloc`, and, `free` functions are implemented using two underlying `system calls` in the __glibc__ library.

    1. `brk` - Expands the heap memory by adjusting the `break pointer` so that it moves to a _valid higher memory address_. Return 0 on success.

        * `int brk(const void *addr);`

    2. `sbrk` - Expand the heap by adjusting the `break pointer` by the specified number of bytes.

        * `void sbrk(intptr_t incr);`

4. __Block Types__ - In `heap memory` there are two main types of `block`:

    1. `data block` : The actual data of the amount reserved. The `pointer` to the data points to the starting address of this block.

    2. `meta block` : Some `meta data` for a `data block`. It is always the same size.

        1. `size` - _integer_ - This record the size (an other properties) of the `data block` so it can be `freed`.

        2. `next` - _pointer_ - A pointer to the next data block if it exists.

        3. `is_free` - _boolean_ - Denotes if the data block is in use or freed. 

    ```
    +-----------+------------------+---------+---------------------------------------------------------------+
    | MetaBlock | Data Block  ...  | Padding |   ... Heap Segment ---                                        |
    +-----------+------------------+---------+---------------------------------------------------------------+
    ```

5. __Padding (4-Byte Alignment)__ - The the sie of the `meta + data` blocks should be divisible by 4.

    * Additional bytes are used as `padding` if required.

6. __Allocation and Deallocations__ 

    1. When a process _allocates_ memory, it iterates over the heap `block list`.

        1. If there is a `is_free = false` block with enough capacity, this capacity is used. The block is split into two blocks.
        
        2. Otherwise it is taken from the `break pointer` position, and the heap size is increased.

    2. When a process _deallocates_ memory the meta block is marked as not in use. 

7. __Block Splitting__ - If free memory block can be used to fulfil an allocation, two blocks are created:

    1. `new allocated` - The newly allocated `meta + data + pad` block.

    2. `new free` - The new remaining unallocated `meta + data + pad` block.

    > This leads to waste where meta data blocks are larger in size than the data blocks they are tracking.

    > It is bad programming practice to use malloc to issue small segments of memory.

9. __Block Merging__ - Find contiguous _free_ `meta + data + pad` blocks and merge them together.

    * This is performed when searching for space to allocate blocks. 

9. __Fragmentation__ - This occurs when there is enough non-contiguous free space allocated on the heap, but, no block is large enough to fulfil the allocation request and the break pointer must be allocated to provide more space.

    1. __Internal Fragmentation__ - Small amounts of free non contiguous memory occurs from block splitting.

    2. __External Fragmentation__ - This occurs when there is enough non-contiguous free space allocated.

