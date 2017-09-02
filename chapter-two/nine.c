#include <stdio.h>
#include <stdlib.h>

/*
* Exercise 2-9 of The C Programming Language
*
* In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x.
* Explain why. Use this observation to write a faster version of bitcount.
*

Original bitcount:
for(b=0; x!=0; x >>= 1)
       if (x & 01)
           b++;

Shifts bits to right by 1 and then performs logical AND
For example, 11000011 would now be 01100001 after '>>';
then it applies AND then produces the corresponding 0 or 1 value

Using x &= x -1 cuts out the middleman and is faster than shifting;
there is no moving of numbers. x - 1 converts 0s to 1s and vice-versa

*/

int bitcount(unsigned x);

int main(int argc, char **argv)
{
	int val = 28;

	printf("%d\n",bitcount((unsigned)val));
	return 0;
}

int bitcount(unsigned x) {
	int b;

	// replace '>>' with &= x - 1 to make this faster
	for (b = 0; x != 0; x &= x-1 )
	{
			b++;
		}
	return b;
}
