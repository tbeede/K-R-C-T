CC=g++ -g -O0
CFLAGS= -Wall
LDFLAGS= -L/usr/include/libvirt 
VG = valgrind --leak-check=yes 
DEBUG = gdb


all: vcpu_scheduler

vcpu_scheduler: vcpu_scheduler.cc
	$(CC) -o vcpu_scheduler vcpu_scheduler.cc $(LDFLAGS) -lvirt

clean:
	/bin/rm -f vcpu_scheduler *.o

valgrind:
	$(VG) ./vcpu_scheduler 12

run: vcpu_scheduler
	./vcpu_scheduler 12

debug: vcpu_scheduler
	$(DEBUG) ./vcpu_scheduler 12

