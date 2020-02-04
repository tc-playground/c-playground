# SDK

## GCC Compiler

---

## GDB Debugger

* `gcc -Wall -g <program>.c` - Compile with debug symbols preserved using `-g`.

* `gdb <program> [--args <arg1> ... <argN>]` - Open the specified executable in _gdb_.

* `tui enable` - Open Text User Interface panel to show debug state.

    * `tui reg all` - Show all registers.
    
    * `layout next` - Go to next TUI info pane.

* `set args <arg1> <arg2>` - Set the arguments to main.

* `run` - Start execution.

* `start` - Start execution and break at main.

* `list` - List the current source file.

* `<ctrl+c>` - Halt execution.

* `next` / `n` - Go to the next line and execute it.

* `step` / `s` - Step into a function and execute the first line. Move forward one machine instruction.

* `reverse-stepi` - Step backward one machine instruction.

* `continue ` / `c` - Continue until the next breakpoint is reached.

* `refresh` / `<ctrl-L> - Refresh.

* `break <POINT>` - Set a breakpoint: line number, function, etc.

    * `break main` - Break point on main function.

    * `break main.c:10`  - Breakpoint on main.c file, line 10.

* `clear <POINT>` - Clear a breakpoint: line number, function, etc.

* `info break` - List breakpoints.

* `watch <VARIABLE>` - Watch the value of a variable.

* `print <VARIABLE>` - Display the value of a variable.

* `print *<ARRAY>@<LEN>` - Display the value of an array of the specified length. `*` dereferences the elements in the array.

* `print $pc` - Print the _Program Counter_.

* `examine $1` / `x $1` - Examine memory the contents of the specified address.

* `backtrace full` / `bt full` - Get the stack trace after a _Segmentation Fault_.

* `record` - Record a session to allow reverse debugging.

* `disassembly` / `dissam` - Get the disassembly for the current function.

* `whatis $var` - Get type of variable.

* `<ctrl-p>` / `<ctrl-n>` - Previous and next command. 

* `python print("Hello World");` - Run embedded python interpreter.

* `gdb -c core.259` - Debug a core dump.

---

## References

* [GDB Tutorial](https://www.youtube.com/watch?v=bWH-nL7v5F4)

* [GDB Tip and Tricks](https://www.youtube.com/watch?v=PorfLSr3DDI)

* [GDB - A lot more than you Knew](https://www.youtube.com/watch?v=-n9Fkq1e6sg)

* [Quick Intro](https://web.eecs.umich.edu/~sugih/pointers/gdbQS.html)
