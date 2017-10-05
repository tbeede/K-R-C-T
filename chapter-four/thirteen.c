#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* Exercise 4-13 of The C Programming Language
*
* Write a recursive version of the function reverse(s),
* which reverses the string s in place.
*
*

12345 -> 54321

12345
52341
54321
*
*/

void reverse(char s[]);
void reverseHelper(char s[], int i, int j);
void swap(char s[], int i, int j);

int main(int argc, char **argv)
{
	reverse(argv[1]);
	printf("REVERSE ME!!! %s\n", argv[1]);
	return 0;
}

void reverse(char s[])
{
	reverseHelper(s,0,strlen(s) - 1);
}

//hard code values into swap that will give us the answer--no parameters
void reverseHelper(char s[], int i, int j) {
	if (i >= j) {
		return;
	}
	swap(s,i,j);
	reverseHelper(s,i + 1,j - 1);
}

//given a string and two indeces I will swap the characters at those indeces
void swap(char s[], int i, int j) {
	char stow;
	//12345
	stow = s[i];
	//52345
	s[i] = s[j];
	//52341
	s[j] = stow;
}
