# Netlink Message Format

## Netlink Message Format

```
+-------------------------------+---------+---------------------------------------------------+
| Netlink Message Header (16 B) | Padding | Payload                                           |
+-------------------------------+---------+---------------------------------------------------+
```

## Cascaded Netlink Messages

```
+--------+---------+---------+--------+---------+---------+
| Header | Padding | Payload | Header | Padding | Payload |
+--------+---------+---------+--------+---------+---------+
```

* `Netlink Messages` can be be cascaded one after another. Any number of messages can be appended.

----

## Netlink Message Header

```c
struct nlmsgh {
    u32 nlmsg_len;
    u16 nlmsg_type;
    u16 nlmsg_flags;
    u32 nlmsg_seq;
    u32 nlmsg_pid; 
}
```

1. __Length__ - Total length of message (Header + Padding + Payload) 

2. __Type__ - `4 Generic Types` are defined in `/usr/include/linux/netlink.h`, and, also space for `user-defined` types:

    1. `NLMSG_NOOP` - _0x1_ : An ACK message. Do nothing but reply with a `NLMSG_DONE`.

    2. `NLMSG_ERROR` - _0x2_ : Return to state a requested action code not be performed.

    3. `NLMSG_DONE` - _0x3_ : Use to acknowledge a `NLMSG_NOOP` and also denoted the end of a `netlink message cascade`.

    4. `NLMSG_OVERRUN` - _0x4_ : Not currently used.

    5. __User defined__ - _0x10_ : User defined types. Binary packed into 4 bytes. Should be > 16.

3. __Flags__ - There are `8 Netlink Message Flags`. Multiple flags can be set by using bitwise AND/OR operations.

    1. `NLM_F_REQUEST` - Must be set for US -> KS communication.

    2. `NLM_F_CREATE_` - USP requesting KS to _create_ a resource/configuration.

    3. `NLM_F_EXCL` - Used with `NLM_F_CREATE` to specify an error should be returned if the operation fails. 

    4. `NLM_F_REPLACE` - USP requesting KS to _replace_ a resource/configuration.

    5. `NLM_F_APPEND` - USP requesting KS to _append_ a resource/configuration.

    6. `NLM_F_DUMP` - USP requesting KS for a _complete dump_ of a resource/configuration.

    7. `NLM_F_MULTI` - Tell the recipient there is another netlink message after this one.

    8. `NLM_F_ACK` - Allow the US to specify the KS it requires a `NLMSG_NOOP` or `NLMSG_ERROR` to be returned.

4. __Sequence Number__ - A unique sequential number that allow requests and response to be correlated. 

    1. When USP sends a netlink request to KS with the `NLM_F_ACK` set, it must also send a unique sequence number. 
    
    2. This is returned in the confirmation to allow it to be correlated.

5. __ProcessId__ - A unique number for a USP (usually the processId) to identify it.

    1. Kernel modules use this to respond back to correct process in Userspace.

---

## Netlink Communication Model

1. Often the `Userspace (US) Application` is the client issuing requests to the `Kernelspace (KS) Kernel Module` server.

2. In `event based notification` implementations the Kernel Module is the initiator of communication.

