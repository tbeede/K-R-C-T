#include <stdio.h>
#include <stdlib.h> /* for atof */
#include <ctype.h>
#include <math.h> /* for fmod */

/*
* Exercise 1-10 of The C Programming Language
*
* Write a program exprcmd, which evaluates a reverse polish expression,
   from the command line,where each operator or operand is a seperate argument.
    For example,
        expr  2 3 4 + *
evaluates 2 X (3 + 4)
*/

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define MAXVAL 100  /* maximum depth of val stack */
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

int getch(void);
void ungetch(char[]);

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;     /* next free position in buf */

/* reverse Polish calculator */
int main(int argc, char **argv)
{
  // int type;

	double op2;
	char s[MAXOP];

	while(--argc > 0)
	{
			ungetch(" ");
			ungetch(*++argv);
			switch(getop(s)) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0) {
          push(pop() / op2);
        }
        else {
          printf("error: zero divisor! \n");
        }
        break;
      case '%':
        op2 = pop();
        if (op2 != 0.0) {
          push(fmod(pop(), op2));
        }
        else {
          printf("error: zero divisor\n");
        }
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command! %s\n", s);
        break;
		}
	}
	printf("\t%.8g\n", pop());
	return 0;
}

/* push: push f onto value stack */
void push(double f)
{
  if (sp < MAXVAL) {
    val[sp++] = f;
  }
  else {
    printf("error: stack full, can't push! %g\n", f);
  }
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if (sp > 0) {
    return val[--sp];
  }
  else {
    printf("error: stack empty! \n");
    return 0.0;
  }
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t') {
    ;
  }
  s[1] = '\0';
  if (!isdigit(c) && c != '.') {
    return c;   /* not a number */
  }
  i = 0;
  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getch())) { /* collect integer part */
      ;
    }
  }
  if (c == '.') {
    while (isdigit(s[++i] = c = getch())) {
      ;
    }
  }
  s[i] = '\0';
  return NUMBER;
}

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char argv[])
{
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters! \n");
  }
  else {
    buf[bufp++] = *argv;
  }
}
