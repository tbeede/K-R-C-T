#include <stdio.h>

/*
* Exercise 3-3 of The C Programming Language
*
* Write a function expand(s1,s2) that
* expands shorthand notations like a-z in the string s1
* into the equivalent complete list abc...xyz in s2.
* Allow for letters of either case and digits,
* and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
* Arrange that a leading or trailing - is taken literally.
*/

#define MAXLINE 100 /* max input line size */

void expand(char s1[], char s2[]);

int main(int argc, char **argv)
{
  char s1[MAXLINE], s2[MAXLINE];

  printf("s1: ");
  scanf("%s", s1);

  expand(s1, s2);
  printf("\n%s\n", s2);
  return 0;
}

/* Take string in s1 and expand in s2 */
void expand(char s1[], char s2[])
{
  int c, i, j;

  i = j = 0;

  while ((c = s1[i]) != '\0') {
    i++;
    if (s1[i] == '-' && s1[i - 1] >= c) {
      i++;
      for (j = 0; (c <= s1[i]) != '\0'; j++) {
        s2[j] = c++;
      }
    }
    else {
      s2[j++] = c;
      }
    }
    s2[j]='\0';
  }
