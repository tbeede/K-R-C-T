#include <stdio.h>
#include <stdlib.h>

/*
* Exercise 2-8 of The C Programming Language
*
* Write a function rightrot(x,n) that returns the
* value of the integer x rotated to the right by
* n bit positions. 
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
