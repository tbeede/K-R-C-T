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

void reverse(char *s[]);
// void reverseHelper(char s[], int i, int j);
void reverseHelper(char *s[], int *i, int j);

void swap(char s[], int i, int j);

// void swap(char *s[], int *i, int *j);

int main(int argc, char **argv)
{
	char *s = argv[1];
	reverse(&s);
	printf("REVERSE ME!!! %s\n", s);
	return 0;
}

void reverse(char *s[])
{
	reverseHelper(s, 0, strlen(*s) - 1);
}

void reverseHelper(char *s[], int *i, int j)
{
	if (i >= j) {
		return;
	}

	swap(s, i, j);
	reverseHelper(s, i + 1, j);
}

/* original swap */
void swap(char s[], int i, int j) {
	char stow;

	stow = s[i];
	s[i] = s[j];
	s[j] = stow;
}

/* the uglier pointer swap */
// void swap(char *s[], int *i, int *j)
// {
// 	char stow;
//
// 	stow = *s[*i];
// 	*s[*i] = *s[*j];
// 	*s[*j] = stow;
// }
