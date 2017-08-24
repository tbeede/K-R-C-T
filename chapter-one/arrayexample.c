#include <stdio.h>

//TODO: WRITE A FACTORIAL THAT INCREMENTS A VALUE BY ONE EACH TIME AND STARTS WITH ZERO
//EXAMPLE: increment(10) returns 10
//increment(5) returns 5
//increment(1) returns 1

int increment(int i) {
	//BASE CASE

	//NORMAL RETURN VALUE
} 

int fac(int val) {
	//BASE CASE
	if (val == 1) {
		printf("%i",val );
		return 1;
	}
	printf("%i * (",val );
	return val * fac(val - 1);
}

int change(int myValue) {
	myValue++; //INCREMENT BY ONE
	return myValue;
}



int main(int argc, char **argv) 
{
	int x = 0; //DEFINE X
	int returnValue = 0;
	int f = 0;
	///BEGIN
	while( f++ < 10) {
	 	returnValue++; //GET INCREMENTED VALUE
		// printf("%i\n",returnValue);
	}
	///END


	// printf("%i %i",x,returnValue);
	int n = 10;
	fac(n);
	while (n-- > 0) {
		printf(")");
	}
	return 0;
}