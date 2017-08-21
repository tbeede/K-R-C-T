CC=gcc
CFLAGS=-O2 -Wall

all: chapter-one

chapter-one: one three four five ten twelve fifteen nineteen

one: one.c
	$(CC) $(CFLAGS) one.c -o one.o

three: three.c
	$(CC) $(CFLAGS) three.c -o three.o

four: four.c
	$(CC) $(CFLAGS) four.c -o four.o

five: five.c
	$(CC) $(CFLAGS) five.c -o five.o

ten: ten.c
	$(CC) $(CFLAGS) ten.c -o ten.o

twelve: twelve.c
	$(CC) $(CFLAGS) twelve.c -o twelve.o

fifteen: fifteen.c
	$(CC) $(CFLAGS) fifteen.c -o fifteen.o

nineteen: nineteen.c
	$(CC) $(CFLAGS) nineteen.c -o nineteen.o

clean:
	rm -f *.o *.gz *~ *.out

tarball:
	make clean
	tar -cvzf chapter-one.tar.gz *
