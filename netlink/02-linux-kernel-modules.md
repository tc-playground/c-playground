# Linux Kernel Module

## Introduction

1. `Linux Kernel Modules` are small pieces of code obeying a specific interface that can be `loaded` and `unloaded` from the kernel on demand.

2. `Linux Kernel Modules` can update the functionality of a system without _recompiling the kernel_ or requiring a _reboot_.

3. `Linux Kernel Modules` are often used to write `devices drivers` and features that run `kernel space`.

4. `Linux Kernel Modules` are managed by a set of commands: `lsmod`, `depmod -a`, `insmod`, `rmmod`, etc.

5. `Linux Kernel Modules` require `linux-header` for the targeted kernel release in-order to compile.

6. `Linux Kernel Modules` must `#include <linux/modules.h>`.

7. `Linux Kernel Modules` must use `module_init` and `module_exit` to define the module life-cycles functions.

8. `Linux Kernel Modules` can also include other metadata such as `MODULE_AUTHOR`, `MODULE_DESCRIPTION`, etc.

9. `Linux Kernel Modules` cannot use standard C library functions. e.g. `printk` must be used for logs.

10. `Linux Kernel Modules` can be built using the defined make files: `make -C /lib/modules/${uname -r} /build M=$(PWD) modules`

11. `Linux Kernel Modules` can have their output inspected with `dmesg` and other logs.
