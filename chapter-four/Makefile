CC=gcc
CFLAGS=-O2 -Wall

all: chapter-four

chapter-four: one three twelve thirteen fourteen

one: one.c
	$(CC) $(CFLAGS) one.c -o one.o

three: three.c
	$(CC) $(CFLAGS) three.c -o three.o

twelve: twelve.c
	$(CC) $(CFLAGS) twelve.c -o twelve.o

thirteen: thirteen.c
	$(CC) $(CFLAGS) thirteen.c -o thirteen.o

fourteen: fourteen.c
	$(CC) $(CFLAGS) fourteen.c -o fourteen.o

clean:
	rm -f *.o *.gz *~ *.out

tarball:
	make clean
	tar -cvzf chapter-one.tar.gz *
