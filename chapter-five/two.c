#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include <math.h>

/*
* Exercise 5-2 of The C Programming Language
*
* Write getfloat, the floating-point analog of getint. What type does
* getfloat return as its function value?
*
* ANSWER: It returns an int.
*/

#define SIZE 1000

int getch(void);
void ungetch(int);

int getfloat(float *);

int main(int argc, char **argv)
{
	float f;
	f = atoi(argv[1]);
	getfloat(&f);
	printf("%f\n", f);
	return 0;
}

int getfloat(float *pn)
{
    int c, sign;

    while(isspace(c = getch())) {
        ;

    if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }
	}
    sign = (c == '-') ? -1: 1;

    if( c == '+' || c == '-') {
			c = getch();
		}
		for(*pn = 0.0; isdigit(c); c = getch()) {
			*pn = 10 * *pn + (c - '0');

			if(c == '.') {
				c = getch();
			}

			if(c != EOF) {
				ungetch(c);
			}
		}
		return c;
}

//from pg. 79
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE) {
			printf("ungetch: too many characters\n");
		}
    else {
			buf[bufp++]=c;
		}
}
