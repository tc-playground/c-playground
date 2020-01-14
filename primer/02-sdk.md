# SDK

## GCC Compiler

---

## GDB Debugger

1. `gcc -Wall -g <program>.c` - Compile with debug symbols preserved using `-g`.

2. `gdb <program> [--args <arg1> ... <argN>]` - Open the specified executable in _gdb_.

2. `tui enable` - Open Text User Interface panel to show debug state.

    * `tui reg all` - Show all registers.
    
    2. `layout next` - Go to next TUI info pane.

3. `set args <arg1> <arg2>` - Set the arguments to main.

3. `run` - Start execution.

4. `start` - Start execution and break at main.

4. `list` - List the current source file.

4. `<ctrl+c>` - Halt execution.

5. `next` / `n` - Go to the next line and execute it.

5. `step` / `s` - Step into a function and execute the first line.

5. `continue ` / `c` - Continue until the next breakpoint is reached.

* `refresh` / `<ctrl-L> - Refresh.

* `break <POINT>` - Set a breakpoint: line number, function, etc.

    1. `break main` - Break point on main function.

    2. `break main.c:10`  - Breakpoint on main.c file, line 10.

* `clear <POINT>` - Clear a breakpoint: line number, function, etc.

* `info break` - List breakpoints.

* `print <VARIABLE>` - Display the value of a variable.

* `print *<ARRAY>@<LEN>` - Display the value of an array of the specified length. `*` dereferences the elements in the array.

* `watch <VARIABLE>` - Watch the value of a variable.

* `backtrace full` - Get the stack trace after a _Segmentation Fault_.

* `<ctrl-p>` / `<ctrl-n>` - Previous and next command. 

* `python print("Hello World");` - Run embedded python interpreter.

---

## References

* [GDB Tutorial](https://www.youtube.com/watch?v=bWH-nL7v5F4)

* [GDB Tip and Tricks](https://www.youtube.com/watch?v=PorfLSr3DDI)

https://www.youtube.com/watch?v=-n9Fkq1e6sg

* [Quick Intro](https://web.eecs.umich.edu/~sugih/pointers/gdbQS.html)



