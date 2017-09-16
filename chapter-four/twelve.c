#include <stdio.h>
#include <stdlib.h>

/*
* Exercise 4-12 of The C Programming Language
*
* Adapt the ideas of printd to write a recursive version of itoa;
* that is, convert an integer into a string by calling a recursive routine.
*/

void itoar(int n, char s[]);

int main(int argc, char **argv)
{
	int n;
	char s[100];

	n = -1977;

	itoar(n, s);
	printf("%s\n", s);
  return 0;
}

/* Recursive function of itoa */
void itoar(int n, char s[])
{
	static int i;

	if (n / 10) {
		itoar(n / 10, s);
	}
	if (n > 0) {
		s[i++] = n % 10 + '0';
	}
	else {
		if (n < 0) {
			s[i++] = '-';
			n = -n;
		}
	}
	s[i] = '\0';
}

/* ORIGINAL ITOA FUNCTION FOR REFERENCE
 * itoa:  convert n to characters in s */
void itoa(int n, char s[])
{
		int i, sign;

		if ((sign = n) < 0)  /* record sign */
				n = -n;          /* make n positive */
		i = 0;
		do {       /* generate digits in reverse order */
				s[i++] = n % 10 + '0';   /* get next digit */
		} while ((n /= 10) > 0);     /* delete it */
		if (sign < 0)
				s[i++] = '-';
		s[i] = '\0';
}
