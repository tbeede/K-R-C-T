#include <stdio.h>

/*
 * Exercise 1-4 of The C Programming Language
 *
 * Write a program to print the corresponding Celsius to Fahrenheit table.
 */

int main() 
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0; //Lower limit of temperature table
	upper = 300; //Upper limit of temperature table
	step = 20; //Step size

	printf("Celsius Fahr\n");
	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0/5.0) * celsius - 32.0;
		printf("%6.1f %3.0f\n",celsius,fahr);
		celsius = celsius + step;
	}
	return 0;
}
