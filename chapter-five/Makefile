CC=gcc
CFLAGS=-O2 -Wall

all: chapter-five

chapter-five: pointers

one: pointers.c
	$(CC) $(CFLAGS) pointers.c -o pointers.o

clean:
	rm -f *.o *.gz *~ *.out

tarball:
	make clean
	tar -cvzf chapter-five.tar.gz *
