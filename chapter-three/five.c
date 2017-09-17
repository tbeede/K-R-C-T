#include <stdio.h>
#include<string.h>
#include <stdlib.h>

/*
* Exercise 3-5 of The C Programming Language
*
* Write the function itob(n,s,b) that converts the integer n into a base b
* character representation in the string s. In particular, itob(n,s,16)
* formats s as a hexadecimal integer in s.
*/

void itob(int n, char s[], int base);
void reverse(char s[]);

int main(int argc, char **argv)
{
	int number, binary, hex;
	char str[100];

	number = atoi(argv[1]);
  binary = 2;
	hex = 16;

	// char s[] = str. This is the string that is returned
  itob(number, str, binary);
  printf("\nbinary: %s\n", str);

	itob(number, str, hex);
  printf("\nhexidecimal: %s\n", str);
	return 0;
}

/* modified the function 'itoa' from page 64
* 'n' = number to convert, 'char s[]'' is converted number,
* int 'base' is the base to convert to
*/
void itob(int n, char s[], int base)
{
	int i, c, sign;

	if ((sign = n) < 0) { 	 			/* record sign */
		n = -n; 							 			/* make n positive */
	}
	i = 0;
	do {
		/* original code used ternary; split up to make more readable
		* s[i++] = (c = n % base, (c <= 9)) ? c + '0' : c + 'A' - 10;
		*/
		c = n % base;
		if (c <= 9) {
			s[i++] = c + '0';
		}
		else {
			s[i++] = c + 'A' - 10;
		}
	} while ((n /= base) > 0);
	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}

/* ORIGINAL ITOA FUNCTION FOR REFERENCE
"itoa:  convert n to characters in s" */
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
		reverse(s);
}

/* reverse: reverse string s in place; taken from page 62 */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j] = c;
	}
}
