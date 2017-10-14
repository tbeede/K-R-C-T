#include <stdio.h>
#include<stdlib.h>
// #include<string.h>

/*
 * Exercise 5-5 of The C Programming Language
 *
 * Write versions of the library functions strncpy, strncat and strncmp,
 * which operate on at most the first n characters of their argument
 * strings. For example, strncpy(s,t,n) copies at most n characters of
 * t to s. Full descriptions are in Appendix B.
 */

void _strncat(char *, const char *, int);
void _strncpy(char *, char *, int);
int _strncmp(char *,char *, int);

int main(int argc, char **argv)
{
	char *s = argv[1];
  char *t = argv[2];
	int n = atoi(argv[3]);

    _strncat(s, t, n);
    printf("%s\n",t);

		_strncpy(s, t, n);
		printf("%s\n",t);

		_strncmp(s, t, n);
		printf("%s\n",t);

		return 0;
}

void _strncat(char *s, const char *t, int n)
{
    while (*s) {
        s++;
			}
    while (*t && n-- > 0) {
        *s++ = *t++;
			}
    *s = '\0';
}

void _strncpy(char *s, char *t, int n)
{
	while ((*s++ = *t++) != '\0') {
		n--;
	}
}

int _strncmp(char *s,char *t, int n)
{
    for( ; *s == *t; s++, t++)
        if( *s == '\0' || --n <= 0)
            return 0;
    return *s - *t;
}
