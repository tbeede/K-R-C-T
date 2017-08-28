#include <stdio.h>
#include <string.h>

/*
* Exercise 2-3 of The C Programming Language
*
* Write the function htoi(s), which converts a string of hexadecimal
* digits (including an optional 0x or 0X) into its equivalent integer
* value. The allowable digits are 0 through 9, a through f, and A
* through F.
*/

#define MAXLENGTH 100 /* max input line size */

#define YES 1
#define NO 0

int read_line(char line[], int maxline);
int htoi(char hexstr[]);

int main(int argc, char **argv)
{
	char line[MAXLENGTH];     /* current input line */

	printf("\nInput hex: ");
  read_line(line, MAXLENGTH);
	printf("\nThe conversion is: %d\n", htoi(line));
  return 0;
}

/* read_line: read a string into array; return string length */
int read_line(char array[], int lim)
{
  /* where c gets the character from i, the input */
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		array[i] = c;

	if (c == '\n')
		array[i] = c;
		++i;

	array[i] = '\0';
	return i;
}

/* htoi:  convert s to integer */
int htoi(char s[])
{
  int hexdigit,i,n, c; //inhex

  n = 0;
  //i = 0;

  //inhex = YES;

 for (i = 0; (c = s[i]) != '\0'; ++i) {
  if (c >= '0' && c <= '9')
  hexdigit = c - '0';

  else if (c >= 'a' && c <='f')
  hexdigit = c -'a' + 10;

  else if (c >= 'A' && c <='F')
  hexdigit = c -'A' + 10;

  else
    return n;

    // if(inhex == YES)
     n = 16 * n + hexdigit;
}
  return n;

}
