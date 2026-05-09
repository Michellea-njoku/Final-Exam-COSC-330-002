CC = gcc
CFLAGS = -Wall -fPIC

all: static shared shell

static: mylib.o
        ar rcs libmylib.a mylib.o

shared: mylib.o
        $(CC) -shared -o libmylib.so mylib.o -lm

mylib.o: mylib.c mylib.h
        $(CC) $(CFLAGS) -c mylib.c

shell: shell.c libmylib.so
        $(CC) -o shell shell.c -L. -lmylib -lm

run:
        LD_LIBRARY_PATH=. ./shell

clean:
        rm -f *.o *.a *.so shell
