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
*
*/

void expand(char s1[], char s2[]);

int main(int argc, char **argv)
{
  char s1, s2* = "foo";


if( argc < 2 ) {
  printf("Usage: \n./three a-z");
  exit(1);
 }
  s1 = argv[1];
 //NOT A CASE YOU NEED TO HANDLE
 // else if( argc > 2 ) {
 //   printf("Too many arguments supplied.\n");
 // }
 

  printf("%s s1: ", s1);

  expand(s1, s2);
  printf("\n%s s2: \n", s2);
  return 0;
}

/* Take string in s1 and expand in s2 */
void expand(char s1[], char s2[])
{
  int c, i, j;

  i = 0;

  // get character (c) and proceed through checks
  while ((c = s1[i]) != '\0') {
    i++;
    // check if s1 equals a '-' and then keep going to get the next character in string
    if (s1[i] == '-' && s1[i + 1] >= c) {
      i++;
      /* iterate through rest of characters to store in s2--note: using 'c <='  instead of 'c <'
      has the undesireable effect of appending an extra character in the returned s2 string */
      for (j = 0; (c < s1[i]) != '\0'; j++) {
        s2[j] = c++;
      }
    }
    // without incrementing through j, does not append last character in s2 string
    else {
      s2[j++] = c;
      }
    }
    s2[j]='\0';
  }
