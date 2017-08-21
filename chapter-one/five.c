#include <stdio.h>

/*
 * Exercise 1-5 of The C Programming Language
 *
 * Modify the temperature conversion program to print the table 
 * in reverse order, that is, for 300 degrees to 0.
 */

int main() 
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0; //Lower limit of temperature table
	upper = 300; //Upper limit of temperature table
	step = 20; //Step size

	printf("Fahr Celsius\n");
	fahr = upper;
	while (fahr >= lower) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n",fahr,celsius);
		fahr = fahr - step;
	}
	return 0;
}
