#include <stdio.h>
#include <stdlib.h>

/*
 * Exercise 2-10
 *
 * Rewrite the function lower, which converts
 * upper case letters to lower case, with a
 * conditional expression instead of if-else.
 *
 */

#define MAXLINE 100 /* max input line size */

int read_line(char line[], int maxline);
int lower(int c);

int main(int argc, char **argv)
{
	int c;

	while ((c = getchar()) != EOF)
		putchar(lower(c));
		return 0;
}

int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
