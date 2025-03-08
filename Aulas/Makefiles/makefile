#makefile2
#lufer

CC=gcc
CFLAGS=-I.
DEPS = Funcs.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: file1.o file2.o 
	$(CC) -o $@ file1.o file2.o 

