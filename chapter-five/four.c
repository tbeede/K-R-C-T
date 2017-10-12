#include <stdio.h>
#include <string.h>
/*
 * Exercise 5-4 of The C Programming Language
 *
 * Write the function strend(s,t), which returns 1 if the string t
 * occurs at the end of the string s, and zero otherwise.
*/

int strend(char *s, char *t);

int main(int argc, char **argv)
{
	char* s = argv[1];
	char* t = argv[2];
	printf("%d\n", strend(s, t));
	return 0;
}

int strend(char *s, char *t)
{
	s += strlen(s) - 1;
	t += strlen(t) - 1;
	if (*s == *t) {
		return 1;
	}
	else {
		return 0;
	}
}
