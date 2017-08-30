#include <stdio.h>
#include <stdbool.h>

//COMPUTER MATH 
//one hundred and eleven <--> 111
//Base 10
//111 = 100 + 10 + 1
//Base 2 (binary) 10 + (1 + 1)
//1000 * 0 + 100 * 0 + 10 * 0 + 1 * 4
//(8 * 0) + 4 * 1 + 2 * 0 + 1 * 0
//111 + 1 = 1000
//111 = ? + ? + 1
// 90 + 9
//Base 16 (hex)
//111 = ? + ? + ?
//base 2 - "ones place"
//0 1
//base 10 - "ones place"
//0 1 2 3 4 5 6 7 8 9
//base 16 - "ones place"
//0 1 2 3 4 5 6 7 8 9 a b c d e f

//HOMEWORK UNDERSTAND QUESTION THREE
void booleans() {

	printf("%lu\n",sizeof(char));
	printf("%lu\n",sizeof(int));
	printf("%lu\n",sizeof(unsigned long));

	bool trueOrFalse = -9223372036854775808;//any value that isn't 0 is true
	putchar(trueOrFalse+'0');
	printf("\n");
	printf("%lu\n",sizeof(trueOrFalse));
	trueOrFalse = 0;
	putchar(trueOrFalse+'0');
}

void types() {
	long a = 3;
	int b = 4;
	printf("%s\n", a < b ? "true" : "false" );
}

int main() {
	booleans();
	return 0;
}