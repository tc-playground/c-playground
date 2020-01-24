# Introduction

1. `Kernel Modules (KMs)` are pieces of code that can be `loaded` and `unloaded` into the kernel upon demand without restarting the machine.

2. `KMs` have:

    1. __Name__ - A normal name e.g. `mymod`.

    2. __Generic Identifier__ - An identifier e.g. `mymod-0-0-1`. This can be used to look up the module name in: `/etc/modprobe.conf`

3. `KMS` are loaded by `modprobe`. This consults the `module.dep` file for the running kernel release and execute `inmod` for ewch dependency.

    ```
    modprobe msdos
    ==>
    insmod /lib/modules/2.6.11/kernel/fs/fat/fat.ko
    insmod /lib/modules/2.6.11/kernel/fs/msdos/msdos.ko
    ```

4. Modules are `versioned` and must be compiled for the `release` of the kernel they are deployed to.

    * `/lib/modules/$(uname -r)`

---

## Commands

* `lsmod` - _List_ kernel modules. Derived from `/proc/modules`.

* `depmod -a` - _Generate_ the `/lib/modules/$KERNEL_RELEASE/module.dep` dependency files.

* `insmod /lib/modules/$KERNEL_RELEASE/kernel/$PATH_TO_MODULE.ko` - _Load_ a specific kernel module. Requires the full path to the module. 

* `modprobe $MODULE` - _Load_ %MODULE and any of its dependencies. Requires just the module name.

* `modinfo $MODULE` - Get information on the specified $MODULE.

* `rmmod $MODULE` - Remove the the specified $MODULE.

---

## Daemons

* `kmod` - When the kernel needs a feature that is not resident, the kernel module daemon execs `modprobe` to load the module.

---

## Files

* `/proc/modules` - List of kernel modules expressed in `procfs`.

* `/lib/modules/${KERNEL_RELEASE}` - Modules for specific kernel builds. `uname -r` will obtain the kernel release.

* `/lib/modules/${KERNEL_RELEASE}/module.dep` - List of kernel modules and their dependencies.

* `/etc/modprobe.conf` - Kernel module configuration for `modprobe`. __Distribution Dependent__. Use `strace modprobe dummy` to find out more.

