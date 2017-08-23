#include <stdio.h>

/*
 * Exercise 1-4 of The C Programming Language
 *
 * Write a program to print the corresponding Celsius to Fahrenheit table.
 */

int main()
{
	int fht;
  printf("Celsius\t | \tFarenheit\n");
  for (fht = 0; fht <= 300; fht = fht + 20)
    printf("%6.1f\t\t | \t%3d \n", (5.0/9.0) * (fht+32.0), fht);
}
