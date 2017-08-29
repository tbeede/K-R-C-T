#include <stdio.h>
#include <stdlib.h>

/*
* Exercise 2-4 of The C Programming Language
*
* Write an alternative version of squeeze(s1,s2)
* that deletes each character in s1 that matches
* any character in the string s2.
*/

#define MAXLINE 100 /* max input line size */

int read_line(char line[], int maxline);
void squeeze(char s1[],char s2[]);

int main(int argc, char **argv)
{

	char s1[MAXLINE],s2[MAXLINE];

    putchar('s');
    putchar('1');
		read_line(s1, MAXLINE);

    putchar('s');
    putchar('2');
		read_line(s2, MAXLINE);

    squeeze(s1, s2);

    printf("\n%s\n", s1);
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

void squeeze(char s1[],char s2[])
{
    int i, j, k;
    k = 0;

    for(i = 0; s1[i] != '\0';++i)
    {
        for(j = 0; (s1[i] != s2[j]) && s2[j] != '\0'; ++j)
            ;
        if(s2[j] == '\0')
            s1[k++] = s1[i];
    }

    s1[k] = '\0';
}
