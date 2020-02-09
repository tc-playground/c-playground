# Netlink Sockets

## Introduction

1. `Netlink` provide a clean bidirectional communication channel between `user space` and `kernel space`.

---

## Linux Layered Architecture

1. A computer consists 3 main abstraction layers: `Hardware`, `Kernel Space`, `User Space`

    ```
    User Space   | App1    App2    App3 <--- IPC ---> App4
                 |
    -------------+----------------------------------------------------
                 |
    Kernel Space | Kernel + [Kernel Modules: Device Drivers]
                 |
    -------------+----------------------------------------------------
                 |
    Hardware     | CPU    Memory    Disks    NW    Other Devices
    ```

3. `User Space` is where normal user `processes` and `applications` run.

    1. A `userspace process` can communicated with another `userspace process` via an `IPC` mechanism:

        1. `Shared Memory`

        2. `Unix Domain Sockets`

    2. A `userspace process` can communicate with `kernel space` via:

        1. `System Calls` - Specialised `system calls` for specific operations `read`, `write`, etc.

        2. `ioctls System Call` -  Generic `system call` for device-specific input/output operations which cannot be expressed by regular system calls.

        3. `Device Files` - Special kernel memory configuration regions that are mapped to `user space` via the `proc` and other `virtual files systems`.

        4. `Netlink` - USerspace Sockets that communicate with Kernel Modules.

    > Userspace process can only access `hardware resources` via the kernel.

---

## Unix Sockets

1. `Sockets` provides a `unified interface` (via the `socket abstraction`) when communicating between two process.

    ```c
    int skt_fd = socket(Socket Address Family, SocketType, ProtocolID)
    ```

    1. __Socket Address Family__ - `AF_INET`, `AF_UNIX`, etc. the format of the address structure to be used on socket APIs.

    2. __Socket Type__ - `Datagram` or `Stream`.

    4. __Protocol__ - `tcp`, `udp`, `netlink`, etc. number.

    * The abstraction lets us specify `whom`, `what` and `how`  to communicate.

2. `Sockets` are defined by the `socket interface` that is a set of `system calls`:

    1. `socket`

    2. `accept`

    3. `bind`

    4. `send`

    5. `receive`

    6. `close`

3. `Sockets` are an abstraction that covers various use case:

    1. __Local USerspace Process to Remote Machines__ - `TCP Sockets`, `UDP Sockets`.

    2. __Local Userspace Process to Process__ - `Unix Domain Sockets`.

    3. __Local Userspace Process to Kernelspace__ - `Netlink Sockets`. 

4. `Socket` programming typically involves the following steps:

    1. Create socket.

    2. Specify the `source` and `destination` address.

    3. Bind the socket.

    4. Send / Receive messages.

    5. Close socket.


---

## Netlink Sockets

1. `Netlink` provide a clean bidirectional communication channel between `user space` and `kernel space`.

2. `Netlink` provides a `unified interface` (via the `socket abstraction`) when communicating with the kernel.

3. `Netlink` provides a mechanism for talking to the `kernel subsystems`

    1. Routing, TCP/IP stack, etc.

    2. Firewall, IP Tables, etc.

    3. ARP tables, etc.

