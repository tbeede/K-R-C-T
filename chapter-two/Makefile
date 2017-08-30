CC=gcc
CFLAGS=-O2 -Wall

all: chapter-two

chapter-two: one three four five eight nine ten

one: one.c
	$(CC) $(CFLAGS) one.c -o one.o

three: three.c
	$(CC) $(CFLAGS) three.c -o three.o

four: four.c
	$(CC) $(CFLAGS) four.c -o four.o

five: five.c
	$(CC) $(CFLAGS) five.c -o five.o

eight: eight.c
	$(CC) $(CFLAGS) eight.c -o eight.o

twelve: nine.c
	$(CC) $(CFLAGS) nine.c -o nine.o

fifteen: ten.c
	$(CC) $(CFLAGS) ten.c -o ten.o

clean:
	rm -f *.o *.gz *~ *.out

tarball:
	make clean
	tar -cvzf chapter-two.tar.gz *
