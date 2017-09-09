CC=gcc
CFLAGS=-O2 -Wall

all: chapter-three

chapter-three: one three five

one: one.c
	$(CC) $(CFLAGS) one.c -o one.o

three: three.c
	$(CC) $(CFLAGS) three.c -o three.o

five: five.c
	$(CC) $(CFLAGS) five.c -o five.o

arrayexample: arrayexample.c
	$(CC) $(CFLAGS) arrayexample.c -o arrayexample.o

clean:
	rm -f *.o *.gz *~ *.out

tarball:
	make clean
	tar -cvzf chapter-one.tar.gz *

