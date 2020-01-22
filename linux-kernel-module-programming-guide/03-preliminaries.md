# 03 - Preliminaries

## Kernel Module Entrypoints

1. Every module must have an `entry function` and an `exit function`.

    1. A module always begins with either the `init_module` or the function you specify with `module_init` call.

    2. A module always ends with either `cleanup_module` or the function you specify with the `module_exit` call.

2. Modules are object files whose `symbols` get resolved upon `insmod`'ing.

3. The definition for the symbols comes from the kernel and exported as the `kernel symbol table`. 

    1. __Kernel Symbol Table__ - `/proc/kallsyms`.

