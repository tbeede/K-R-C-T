#include <stdio.h>
#include <stdlib.h>

/*
* Exercise 1-10 of The C Programming Language
*
* Write a program to copy its input to its output, replacing each
* tab by \t, each backspace by \b, and each backslash by \\. This
* makes tabs and backspaces visible in an unambiguous way.
*/

int main(int argc, char **argv)
{
	int c, tab, backspace, backslash;

	tab = '\t';
	backslash = '\\';
	backspace = '\b';

	while((c = getchar()) != EOF)
	// Note: if else threw errors without the ugly curlies
	// replace with tabs
	if(c == tab)
	{
		putchar('\\');
		putchar('t');
	}

	// replace with backspace (doesn't seem to work; gave up)
	else if(c == backspace)
	{
		putchar('\\');
		putchar('b');
	}

	// replace with backslash
	else if(c == backslash)
	{
		putchar('\\');
		putchar('\\');
	}

	// handle everything else
	else
	{
		putchar(c);
	}

	return 0;
}
