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

	printf("s1: ");
	scanf("%s", s1);

	printf("s2: ");
	scanf("%s", s2);

	squeeze(s1, s2);

	printf("\n%s\n", s1);
	return 0;
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
