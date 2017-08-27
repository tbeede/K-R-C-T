#include <stdio.h>
#include <stdlib.h>

/*
* Exercise 1-19 of The C Programming Language
*
* Write a function reverse(s) that reverses the character string s.
* Use it to write a program that reverses its input a line at a time.
*/

#define MAXLENGTH 50 /* max input line size */

/*
* NOTE: Using function 'getline' from the book produced strange errors.
* Stackoverflow recommended using this function name. Error no longer appears.
*/

int get_line(char line[], int maxline);
void reverses(char s[]);

int main(int argc, char **argv)
{
	int len;            /* current line length */
	char line[MAXLENGTH];     /* current input line */

//TODO: Program does not reverse numbers or symbols
	printf("\nInput line to reverse:\t");
	while ((len = get_line(line, MAXLENGTH)) > 0) {
		reverses(line);
		printf("\nThe line reversed is:\t");
		printf("%s", line);
		return 0;
	}
}

/* get_line: read a line into s; return its length */
int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n')
		s[i] = c;
		++i;

	s[i] = '\0';
	return i;
}

/* reverses:  reverses the character string s */
void reverses(char s[])
{
    int i, len;

    /* get length of string */
    for (len = 0; s[len] != '\0' && s[len] != '\n'; ++len)
        len--;

		/* reverse string */
    for (i = 0; i < len; ++i) {
        s[i] = s[len - 1];
        --len;
    }
}
