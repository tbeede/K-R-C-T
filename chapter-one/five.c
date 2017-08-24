#include <stdio.h>

/*
 * Exercise 1-5 of The C Programming Language
 *
 * Modify the temperature conversion program to print the table
 * in reverse order, that is, for 300 degrees to 0.
 */



int tim() 
{
	int fht;
  	printf("Farenheight\t | \tCelsius\n");
  	for (fht = 300; fht >= 0; fht = fht - 20)
    	printf("%3d\t\t | \t%6.1f \n", fht, (5.0/9.0) * (fht-32.0));
	return 0;
}

 int fToC(int fahr) {
	return (5.0/9.0) * (fahr-32.0);
}

int clay() 
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0; //LOWER LIMIT OF TEMPERATURE TABLE
	upper = 300; //UPPER LIMIT OF TEMPERATURE TABLE
	step = 20; //STEP SIZE

	printf("Fahr Celsius\n");
	fahr = upper;
	while (fahr >= lower) {
		celsius = fToC(fahr);
		printf("%3.0f %6.1f\n",fahr,celsius);
		fahr = fahr - step;
	}
	return 0;
}





int main()
{
	printf("My solution:\n");
	clay();
	printf("Your solution:\n");
	tim();
  }

 