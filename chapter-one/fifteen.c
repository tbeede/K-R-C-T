#include <stdio.h>
#include <stdlib.h>

/*
 * Exercise 1-12 of The C Programming Language
 *
 * Write a program that prints its input one word per line.
 */

#define IN 1
#define OUT 0

/* count lines, words, and characters in input */
int main(int argc, char **argv) 
{
	FILE *fp;
	char* file_name;
	if (argc < 2) {
		file_name = "one.c";
	} else {
		file_name = argv[1];
	}

   	if( (fp = fopen(file_name, "r")) == NULL ) {
      		perror("Error while opening the file.\n");
      		exit(EXIT_FAILURE);
   	}

	int c, state;
	
	state = OUT;

	
	while ((c = fgetc(fp)) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			printf("\n");
		} else if (state==OUT) {
			state = IN;
			printf("%c",c);
		} else {
			printf("%c",c);
		}
	}
	

	fclose(fp);
	return 0;
}
