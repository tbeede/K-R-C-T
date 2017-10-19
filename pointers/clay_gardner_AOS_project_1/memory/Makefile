CC=g++ -g -O0
CFLAGS= -Wall
LDFLAGS= -L/usr/include/libvirt
VG = valgrind --leak-check=yes 
DEBUG = gdb


all: memory_coordinator

memory_coordinator: memory_coordinator.cc
	$(CC) -o memory_coordinator memory_coordinator.cc $(LDFLAGS) -lvirt -lm

clean:
	/bin/rm -f memory_coordinator *.o

valgrind:
	$(VG) ./memory_coordinator 12

run: memory_coordinator
	./memory_coordinator 12

debug: memory_coordinator
	$(DEBUG) ./memory_coordinator 12

