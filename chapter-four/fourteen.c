#include <stdio.h>
#include <stdlib.h>

/*
* Exercise 4-14 of The C Programming Language
*
* Define a macro swap(t,x,y) that interchanges two
* arguments of type t. (Block structure will help.)
*/

#define swap(t,x,y) { t swap; swap = x; x = y; y = swap; }

int main(int argc, char **argv)
{
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);

	printf("x = %d \t y = %d\n", x, y);

	swap(char, x, y);

	printf("x = %d \t y = %d\n", x, y);
	return 0;
}
