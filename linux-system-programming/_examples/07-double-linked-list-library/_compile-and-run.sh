#!/bin/bash

# gcc -g -c dll.c -o dll.o && gcc -g -c dll_util.c -o dll_util.o && gcc -g -c app.c -o app.o && gcc -g dll.o dll_util.o app.o -o app && ./app

# Compile
gcc -g -c app.c -o app.o
gcc -g -c dll.c -o dll.o
gcc -g -c dll_util.c -o dll_util.o
# Link
gcc -g dll.o dll_util.o app.o -o app
# Execute
./app

# Clean
rm app.o dll.o dll_util.o app