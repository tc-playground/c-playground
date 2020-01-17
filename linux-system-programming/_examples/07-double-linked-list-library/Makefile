CC = gcc
# CCFLAGS= -std=c99 -Wall
CCFLAGS = -c -std=c99 -Wall

DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CCFLAGS += -g
endif

# TARGET:app

app: dll.o dll_util.o app.o
	$(CC) -g dll.o dll_util.o app.o -o app

app.o: dll.o dll_util.o
	$(CC) $(CCFLAGS) app.c -o app.o

dll.o:
	$(CC) $(CCFLAGS) dll.c -o dll.o

dll_util.o:
	$(CC) $(CCFLAGS) dll_util.c -o dll_util.o

clean:
	rm -f app app.o dll_util.o dll.o

env:
	@echo "CC      : $(CC)"
	@echo "CCFLAGS : $(CCFLAGS)"

help:
	@echo "1. Debug Build: make DEBUG=1"

