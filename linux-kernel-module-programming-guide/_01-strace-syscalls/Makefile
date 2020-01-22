# Simple Makefile to deonstrate 'strace' to show system calls.

build:
	gcc -Wall simple.c -o simple

run: build
	./simple; echo

trace: build
	strace ./simple

clean:
	rm -f simple

