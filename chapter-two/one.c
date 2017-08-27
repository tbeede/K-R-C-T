#include <stdio.h>
#include <limits.h>

/*
 * Exercise 2-1 of The C Programming Language
 *
 * Write a program to determine the ranges of char, short, int, and long variables,
 * both signed and unsigned, by printing appropriate values from standard headers
 * and by direct computation. Harder if you compute them: determine the ranges of
 * the various floating-point types.
 *
 * Constants for sizes of integral types taken from Appendix B11.
 *
 * NOTE: Took the coward's way out on this one. Once I looked into determining ranges
 * of floats, I realized this exercise had far more to it than initially met the eye.
 * There's no way I can do that part of the exercise without some further reading.
 *
 */

int main()
{
	printf("\n Bits in a char: %d\n", CHAR_BIT);
	printf("\n Maximum value of char: %d\n", CHAR_MAX);
	printf("\n Maximum value of signed char: %d\n", SCHAR_MAX);
	printf("\n Maximum value of unsigned char: %u\n", UCHAR_MAX);
	printf("\n Minimum value of char: %d\n", CHAR_MIN);
	printf("\n Minimum value of signed char: %d\n", SCHAR_MIN);
	printf("\n Maximum value of int: %d\n", INT_MAX);
	printf("\n Maximum value of unsigned int: %u\n", UINT_MAX);
	printf("\n Minimum value of int: %d\n", INT_MIN);
	printf("\n Maximum value of long: %li\n", LONG_MAX);
	printf("\n Maximum value of unsigned long: %lu\n", ULONG_MAX);
	printf("\n Minimum value of long: %li\n", LONG_MIN);
	printf("\n Maximum value of short: %d\n", SHRT_MAX);
	printf("\n Maximum value of unisgned short: %u\n", USHRT_MAX);
	printf("\n Minimum value of short: %d\n", SHRT_MIN);
	return 0;
}
