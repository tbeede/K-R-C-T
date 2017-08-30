#include <stdio.h>

/*
* Exercise 2-3 of The C Programming Language
*
* Write the function htoi(s), which converts a string of hexadecimal
* digits (including an optional 0x or 0X) into its equivalent integer
* value. The allowable digits are 0 through 9, a through f, and A
* through F.
*/

#define MAXLENGTH 100 /* max input line size */

int read_line(char line[], int maxline);
int htoi(char hexstr[]);

int main(int argc, char **argv)
{
  char line[MAXLENGTH];  /* current input line */

  printf("\nInput hex: ");
  scanf("%s", line);
  printf("\nThe conversion is: %d\n", htoi(line));
  return 0;
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

/* htoi:  convert s to integer */
int htoi(char s[])
{
  int hex, i, n, c;

  n = 0;

  for (i = 0; (c = s[i]) != '\0'; ++i) {
    if (c >= '0' && c <= '9')
      hex = c - '0';

    else if (c >= 'a' && c <='f')
      hex = c - 'a' + 10;

    else if (c >= 'A' && c <='F')
      hex = c - 'A' + 10;

    else
      return n;

    n = 16 * n + hex;
  }
  return n;

}
