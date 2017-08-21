#include <stdio.h>
#include <stdlib.h>

/*
 * Exercise 1-10 of The C Programming Language
 *
 * Write a program to copy its input to its output, replacing each
 * tab by \t, each backspace by \b, and each backslash by \\. This
 * makes tabs and backspaces visible in an unambiguous way.
 */

int main(int argc, char **argv) 
{
	FILE *fp;
	char *file_name;
	if (argc < 2) {
		file_name = "two.c";
	} else {
		file_name = argv[1];
	}

   	if( (fp = fopen(file_name, "r")) == NULL ) 
   	{
      		perror("Error while opening the file.\n");
      		exit(EXIT_FAILURE);
   	}
	char c;
	while( ( c = fgetc(fp) ) != EOF ) {
		if (c == '\t') {
			printf("\\t");
		} else if (c == '\\') {
			printf("\\\\");
		} else if (c == '\b') {
			printf("\\b");
		} else {
			putchar(c);
		}
	}
 	fclose(fp);
	return 0;
}
