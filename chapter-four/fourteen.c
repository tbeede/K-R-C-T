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
	char x, y;
	x = 'a', y = 'b';
	printf("x = %c \t y = %c\n", x, y);
	swap(char, x, y);
	printf("x = %c \t y = %c\n", x, y);
	return 0;
}
