# Simple Kernel Module

## Running

1. Build Kernel Module: `make build`

2. Load Kernel Module: `sudo make load`

3. Unload Kernel Module: `make unload`

4. Check logs to see if the kernel modules hooks were executed: `dmesg`

5. Clean: `make clean`

---

## UEFI Secure Boot

1. If `UEFI Secure Boot` is enabled and the kernel was compiled with `kernel_lockdown` enabled then the following error is likely to occur:

    ```
    insmod: ERROR: could not insert module simpleKM.ko: Operation not permitted
    ```

    1. Check the kernel logs with `dmesg`:

        ```
        [  996.368547] Lockdown: insmod: Loading of unsigned module is restricted; see man kernel_lockdown.7
        ```
    
    2. `kernel_lockdown` can be temporally disabled until next boot with `crtl+sys-rq-x`. See:

        * [Linux kernel lockdown and UEFI Secure Boot](https://mjg59.dreamwidth.org/50577.html)

        * [Kernel Lockdown](https://bugzilla.redhat.com/show_bug.cgi?id=1599197)

---

## VSCode Config

```json
{
    "env": {
        "kernel_release": "linux-headers-5.3.0-40-generic"
    },
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "/usr/src//include/linux",
                "/usr/src/${env:kernel_release}/include/**",
                "/usr/src/${env:kernel_release}/include/linux/**",
                "/usr/src/${env:kernel_release}/include/uapi/linux/**",
                "/usr/src/${env:kernel_release}/arch/x86/include/**"
            ],
            "defines": [
                "__KERNEL__",
                "KERN_INFO"
            ],
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "clang-x64"
        }
    ],
    "version": 4
}
```