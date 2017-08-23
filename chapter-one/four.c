#include <stdio.h>
#include <stdlib.h>

/*
 * Exercise 1-4 of The C Programming Language
 *
 * Write a program to print the corresponding Celsius to Fahrenheit table.
 */

/*
WHAT DOES MY CODE SNIPPET DO DIFFERENTLY THAN YOURS?
IF WE WERE TOLD TO CHANGE THE STEP SIZE TO 10 WHICH FUNCTION IS
EASIER TO CHANGE? WHAT ABOUT FOR SOMEBODY WHO WAS GIVEN
THAT TASK WITHOUT EVER SEEING THE CODE BEFORE?
YOU HAVE TOO MANY VARIABLES AND CALCULATIONS INSIDE OF YOUR FUNCTION.
THIS ISN'T ABOUT CODE GOLF BUT INSTEAD ABOUT MAINTAINABILITY
*/


int tim() {
	int fht;
  	printf("Celsius\t | \tFarenheit\n");
  	for (fht = 0; fht <= 300; fht = fht + 20)
    	printf("%6.1f\t\t | \t%3d \n", (5.0/9.0) * (fht+32.0), fht);
	return 0;
}


int clay() 
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0; //LOWER LIMIT OF TEMPERATURE TABLE
	upper = 300; //UPPER LIMIT OF TEMPERATURE TABLE
	step = 20; //STEP SIZE

	printf("Celsius Fahr\n");
	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr + 32.0);
		printf("%6.1f %3.0f\n",celsius,fahr);
		fahr = fahr + step;
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