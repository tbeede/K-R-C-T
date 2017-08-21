#include <stdio.h>

/*
 * Exercise 1-3 of The C Programming Language
 *
 * Modify the temperature conversion program to print a heading above the table.
 */

int main() 
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0; //Lower limit of temperature table
	upper = 300; //Upper limit of temperature table
	step = 20; //Step size

	printf("Fahr Celsius\n");
	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n",fahr,celsius);
		fahr = fahr + step;
	}
	return 0;
}
