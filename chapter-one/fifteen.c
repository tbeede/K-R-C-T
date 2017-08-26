#include <stdio.h>
#include <stdlib.h>

/*
* Exercise 1-15 of The C Programming Language
*
* Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
*/

#define COLDEST 0
#define HOTTEST 300
#define INC 20

float fht, celsius;
int c, hottest, coldest, inc;

void convertToFarenheit();
void convertToCelsius();

int main()
{

	//TODO: while (c != '3')--learn switch statements otherwise prints everything twice {

		printf("\t\t\t\nTemperature Table Program\n");
		printf("\n - Press '1' for Farenheit to Celsius Table\n");
		printf("\n - Press '2' for Celsius to Farenheit Table\n");
		printf("\n - Press '3' to exit\n");
		// TODO: printf("Press '3' for Descending Farenheit to Celsius Table\n");
		// TODO: printf("Press '4' for Descending Celsius to Farenheit Table\n");

		c = getchar();

		if (c == '1')
		convertToFarenheit();

		else if (c == '2')
		convertToCelsius();

		else if (c == '3')
		printf("Goodbye.\n");

		else
		printf("\n\n\nThis isn't that hard.\n\n\n");

	//}

	return 0;
}

void convertToFarenheit()
{
	printf("\nYou chose '1' for Farenheit to Celsius Table\n");
	fht = COLDEST;
	while (fht <= HOTTEST) {
		celsius = (5.0/9.0) * (fht - 32.0);
		printf("\n%3.0f\t\t | \t%6.1f\n", fht, celsius);
		fht = fht + INC;
	}
}

void convertToCelsius()
{
	printf("\nYou chose '2' for Celsius to Farenheit Table\n");
	fht = COLDEST;
	while (fht <= HOTTEST) {
		celsius = (5.0/9.0) * (fht + 32.0);
		printf("\n%6.1f\t\t | \t%3.0f\n", celsius, fht);
		fht = fht + INC;
	}
}
