#include <stdio.h>


int change(int myValue) {
	myValue++; //INCREMENT BY ONE
	return myValue;
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