#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* Exercise 4-13 of The C Programming Language
*
* Write a recursive version of the function reverse(s),
* which reverses the string s in place.
*/

void reverse(char s[]);

int main(int argc, char **argv)
{
	reverse(argv[1]);
	printf("%s\n", argv[1]);
	return 0;
}

void reverse(char s[])
{
	
}

/* original reverse: reverse string s in place; taken from page 62 */
void oreverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
