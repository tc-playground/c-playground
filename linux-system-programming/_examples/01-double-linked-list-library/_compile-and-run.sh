#!/bin/bash

# gcc -g -c dll.c -o dll.o && gcc -g -c app.c -o app.o && gcc -g dll.o app.o -o app && ./app

# Compile
gcc -g -c app.c -o app.o
gcc -g -c dll.c -o dll.o
# Link
gcc -g dll.o app.o -o app
# Execute
./app

# Clean
rm app.o dll.o app