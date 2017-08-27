#include <stdio.h>
#include <stdlib.h>

/*
* Exercise 1-19 of The C Programming Language
*
* Write a function reverse(s) that reverses the character string s.
* Use it to write a program that reverses its input a line at a time.
*/

#define MAXLENGTH 666 /* max input line size */

/*
* NOTE: Using function 'getline' from the book produced strange errors.
* Stackoverflow recommended using this function name. Error no longer appears.
*/

int read_line(char line[], int maxline);
void reverses(char array[]);

int main(int argc, char **argv)
{
	int len;            /* current line length */
	char line[MAXLENGTH];     /* current input line */

	printf("\nInput string to reverse: ");
	while ((len = read_line(line, MAXLENGTH)) > 0) {
		reverses(line);
		printf("\nThe string reversed is: ");
		printf("%s", line);
		return 0;
	}
}

/* read_line: read a string into array; return string length */
int read_line(char array[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		array[i] = c;

	if (c == '\n')
		array[i] = c;
		++i;

	array[i] = '\0';
	return i;
}

/* reverses:  reverses the string array */
void reverses(char array[])
{
    int i, len;
		char c;

    /* get length of string */
    for (len = 0; array[len] != '\0' && array[len] != '\n'; ++len)
        ;

		/* reverse string */
    for (i = 0; i < len; ++i) {
			c = array[i];
        array[i] = array[len - 1];
				array[len - 1] = c;
        --len;
    }
}
