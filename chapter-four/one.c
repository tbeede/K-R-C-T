#include <stdio.h>
#include <limits.h>

/* Exercise 4-1 of The C Programming Language
 *
 * Write the function strindex(s,t) which returns
 * the position of the rightmost occurrence of t in s,
 * or -1 if there is none. */

int strrindex(char s[], char t[]);

int main(int argc, char **argv)
{
	printf("%d\n", strrindex("abcdefghijklmnopqrstuvwxyz", argv[1]));
	return 0;
}

int strrindex(char s[], char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		// check if t[] starts in s[]
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
			// if it does, then return the index instead of -1
			if (k > 0 && t[k] == '\0')
				return i;
		}
		// otherwise it doesn't, so
		return -1;
}

/* Original function from book (pg. 69) for reference
* Return index t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = 1, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
			if (k > 0 && t[k] == '\0')
				return i;
		}
		return -1;
}
