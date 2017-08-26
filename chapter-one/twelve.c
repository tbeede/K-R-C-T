#include <stdio.h>
#include <stdlib.h>

/*
* Exercise 1-12 of The C Programming Language
*
* Write a program that prints its input one word per line.
*/

int main(int argc, char **argv)
{
	int c;
	c = getchar();
	while (c != EOF) {
		// Ensure it still prints one word per line even with tabs and new lines
		if (c == ' ' || c == '\t' || c == '\n' || c == '\b')
			putchar('\n');

		else
			putchar(c);
			c = getchar();
	}
	return 0;
}
