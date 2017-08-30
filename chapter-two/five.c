#include <stdio.h>

/*
* Exercise 2-5 of The C Programming Language
*
* Write the function any(s1,s2),
* which returns the first location in a string s1
* where any character from the string s2 occurs,
* or -1 if s1 contains no characters from s2.
* (The standard library function strpbrk does the same job but returns a pointer to the location.)
*
*/

#define MAXLINE 100 /* max input line size */

int read_line(char line[], int maxline);
int any(char s1[],char s2[]);

int main(int argc, char **argv)
{

	char s1[MAXLINE], s2[MAXLINE];

	putchar('s');
	putchar('1');
	putchar(':');
	putchar(' ');
	read_line(s1, MAXLINE);

	putchar('s');
	putchar('2');
	putchar(':');
	putchar(' ');
	read_line(s2, MAXLINE);

	printf("\n%d\n", any(s1, s2));
	return 0;
}

/* read_line: read a string into array; return string length */
int read_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	s[i] = c;
	if (c == '\n')
	s[i++] = c;

	s[i] = '\0';
	return i;
}

int any(char s1[], char s2[])
{
	int i, j, k;

	for (i = 0; s1[i] != '\0'; i++)
	for (k = 0; s2[k] != '\0'; k++)
	if (s2[k] == s1[i])
	return i;
	return -1;
}
