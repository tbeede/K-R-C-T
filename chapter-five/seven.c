#include <stdio.h>
#include <string.h>

/*
* Exercise 5-7 of The C Programming Language
*
* Rewrite readlines to store lines in an array supplied by main,
* rather than calling alloc to maintain storage.
* How much faster is the program?
*
* This entire solution was copied from pg. 108 with adjustments made
* to solve the problem.
*/

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], char linearray[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

#define ALLOC_SIZE 1000

int main()
{
	int nlines;
	char linearray[ALLOC_SIZE]; /* this is the array to store lines */

	if ((nlines = readlines(lineptr, linearray, MAXLINES)) >= 0) {
		qsort (lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf ("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000
int _getline(char *, int);
/* get rid of original
* char *alloc(int);
* and replace with a parameter that maintains storage within an array
*/
int readlines(char *lineptr[], char linearray[], int maxlines)
{
	int len, nlines;
	char line[MAXLEN], *p;

	nlines = 0;
	p = linearray;

	while ((len = _getline(line, MAXLEN)) > 0){
		if (nlines >= maxlines || linearray == NULL) { /* replace p = alloc(len) with new way of maintaining storage */
			return -1;
		}
		else {
			line[len - 1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p; /* again, replace p with new pointer */
		}
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; ++i)
		printf ("%s\n", lineptr[i]);
}

int _getline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right)
		return;
	swap (v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap (v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

void swap (char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
