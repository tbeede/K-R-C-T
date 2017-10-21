#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Exercise 5-6 of The C Programming Language
 *
 * Rewrite appropriate programs from earlier chapters and exercises with
 * pointers instead of array indexing. Good possibilities include
 * getline (Chapters 1 and 4), atoi, itoa, and their variants
 * (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop
 * (Chapter 4).
 *
 * We will use reverse from chapter 3.
 */

void reverse(char *s);

int main(int argc, char **argv)
{
	char *s = argv[1];
	reverse(s);												//THIS WORKS NOW
	printf("REVERSE ME!!! %s\n", s);
	return 0;
}

// 100,000 -> 10101001
// (100,000+1 == 100,001) -> 01010100
// (100,000+2) -> 10101010
// (100,000+3) -> 10101001
// (100,000+4) -> 10101101
// string: abcde
// memory address in bytes (n) -> a
// memory address in bytes (n + 1) -> b
// memory address in bytes (n + 2) -> c
// memory address in bytes (n + 3) -> d
// memory address in bytes (n + 4) -> e
// abcde
// abcdef
// s is at memory address n
void reverse(char *s)
{
	int offset = strlen(s) - 1;
	char *p1 = s;
	char *p2 = s + offset; //<- memory address

	while(p1 < p2) {
		char stow;					//THIS CHANGE ELIMINATES POINTER CONVERSION WARNINGS

		stow = *p1;
		*p1++ = *p2;
		*p2-- = stow;

		char *stow;					//ORIGINAL

		stow = *p1;
		*p1++ = *p2;
		*p2-- = stow;
	}
}
