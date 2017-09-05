#include <stdio.h>
#include<string.h>

/*
* Exercise 3-5 of The C Programming Language
*
* Write the function itob(n,s,b) that converts the integer n into a base b
* character representation in the string s. In particular, itob(n,s,16)
* formats s as a hexadecimal integer in s.
*/

#define MAXLINE 100

void itob(int n, char s[], int base);
void reverse(char s[]);

int main(int argc, char **argv)
{
	int number, binary, hex;
	char str[MAXLINE];

	number = 10;
  binary = 2;
	hex = 16;

  itob(number, str, binary);
  printf("\nbinary: %s\n", str);

	itob(number, str, hex);
  printf("\nhexidecimal: %s\n", str);
	return 0;
}

/* modified the function 'itoa' from page 64 */
void itob(int n, char s[], int base)
{
	int i, c, sign;

	if ((sign = n) < 0) { 	 			/* record sign */
		n = -n; 							 			/* make n positive */
	}
	i = 0;
	do {
		/* get next digit--change '10' to variable 'base'
		* to represent any base instead of decimal only;
		* if number is less than 10, return number, else
		* subtract 10 and add 'A' to handle hexadecimal */
		// c = n % base;
		s[i++] = (c = n % base, (c <= 9)) ? c + '0' : c + 'A' - 10;
	} while ((n /= base) > 0);
	if (sign < 0) {
		s[i++] = '-';
	}
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
