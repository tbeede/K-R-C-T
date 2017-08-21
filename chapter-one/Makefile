CC=gcc
CFLAGS=-O2 -Wall -g

all: chapter_one

chapter_one: one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty twenty-one twenty-two twenty-three twenty-four

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

thirteen: thirteen.c
	$(CC) $(CFLAGS) thirteen.c -o thirteen.o

fourteen: fourteen.c
	$(CC) $(CFLAGS) fourteen.c -o fourteen.o

fifteen: fifteen.c
	$(CC) $(CFLAGS) fifteen.c -o fifteen.o

sixteen: sixteen.c
	$(CC) $(CFLAGS) sixteen.c -o sixteen.o

seventeen: seventeen.c
	$(CC) $(CFLAGS) seventeen.c -o seventeen.o

eighteen: eighteen.c
	$(CC) $(CFLAGS) eighteen.c -o eighteen.o

nineteen: nineteen.c
	$(CC) $(CFLAGS) nineteen.c -o nineteen.o

twenty: twenty.c
	$(CC) $(CFLAGS) twenty.c -o twenty.o

twenty-one: twenty-one.c
	$(CC) $(CFLAGS) twenty-one.c -o twenty-one.o

twenty-two: twenty-two.c
	$(CC) $(CFLAGS) twenty-two.c -o twenty-two.o

twenty-three: twenty-three.c
	$(CC) $(CFLAGS) twenty-three.c -o twenty-three.o

twenty-four: twenty-four.c
	$(CC) $(CFLAGS) twenty-four.c -o twenty-four.o

clean:
	rm -f *.o *.gz *~ *.out

tarball:
	make clean
	tar -cvzf chapter_one.tar.gz *
