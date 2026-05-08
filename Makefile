CC = gcc
CFLAGS = -Wall -fPIC

all: libmylib.a libmylib.so shell

mylib.o: mylib.c mylib.h
	$(CC) $(CFLAGS) -c mylib.c

libmylib.a: mylib.o
	ar rcs libmylib.a mylib.o

libmylib.so: mylib.o
	$(CC) -shared -o libmylib.so mylib.o

shell: shell.c libmylib.so
	$(CC) -Wall -o shell shell.c -L. -lmylib

clean:
	rm -f *.o *.a *.so shell
