#include <stdio.h>
#include <stdlib.h>

/*
* Exercise 2-4 of The C Programming Language
*
* Write an alternative version of squeeze(s1,s2)
* that deletes each character in s1 that matches
* any character in the string s2.
*/

#define MAXLINE 10 /* max input line size */

int read_line(char line[], int maxline);
void squeeze(char s1[],char s2[]);

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

	squeeze(s1, s2);

	printf("\n%s\n", s1);
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

/* delete each character in s1 that matches any character in the string s2. */
void squeeze(char s1[], char s2[])
{
	int i, j, k, same;

	for (i = j = 0; s1[i] != '\0'; i++) {
		same = 0;
		for (k = 0; s2[k] != '\0' && ! same; k++)
			if (s2[k] == s1[i])
				same = 1;
			if(! same)
				s1[j++] = s1[i];
	}
	s1[j] = '\0';
}
