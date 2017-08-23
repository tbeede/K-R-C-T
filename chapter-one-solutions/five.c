#include <stdio.h>

/*
 * Exercise 1-5 of The C Programming Language
 *
 * Modify the temperature conversion program to print the table
 * in reverse order, that is, for 300 degrees to 0.
 */

int main()
{
	int fht;
  printf("Farenheight\t | \tCelsius\n");
  for (fht = 300; fht >= 0; fht = fht - 20)
    printf("%3d\t\t | \t%6.1f \n", fht, (5.0/9.0) * (fht-32.0));
  }
