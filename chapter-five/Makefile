CC=gcc
CFLAGS=-O2 -Wall

all: chapter-five

chapter-five: pointers two four five six seven ten

one: pointers.c
	$(CC) $(CFLAGS) pointers.c -o pointers.o

two: two.c
	$(CC) $(CFLAGS) two.c -o two.o

four: four.c
	$(CC) $(CFLAGS) four.c -o four.o

five: five.c
	$(CC) $(CFLAGS) five.c -o five.o

six: six.c
	$(CC) $(CFLAGS) six.c -o six.o

seven: seven.c
	$(CC) $(CFLAGS) seven.c -o seven.o

ten: ten.c
	$(CC) $(CFLAGS)	ten.c -o ten.o

clean:
	rm -f *.o *.gz *~ *.out

tarball:
	make clean
	tar -cvzf chapter-five.tar.gz *
