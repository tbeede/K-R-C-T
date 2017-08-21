#include <stdio.h>
#include <stdlib.h>

/*
 * A Frame for Reading a File
 */

int main(int argc, char **argv) 
{
	FILE *fp;
	char* file_name;
	if (argc < 2) {
		file_name = "read-file-template.c";
	} else {
		file_name = argv[1];
	}
	fp = fopen(file_name, "r");
   	if( fp == NULL )  {
      		perror("Error while opening the file.\n");
      		exit(EXIT_FAILURE);
   	}

	char c;

	while ((c = fgetc(fp)) != EOF) {


	}

	fclose(fp);
	return 0;
}
