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

	printf("s1: ");
	scanf("%s", s1);

	printf("s2: ");
	scanf("%s", s2);

	printf("\n%d\n", any(s1, s2));
	return 0;
}

int any(char s1[], char s2[])
{
	int i, j, k;
	//UNMAINTAINABLE CODE
	//NO COMMENTS, NO BRACKETS, NO INDENTATION
	for (i = 0; s1[i] != '\0'; i++)
	for (k = 0; s2[k] != '\0'; k++)
	if (s2[k] == s1[i])
	return i;
	return -1;
}
