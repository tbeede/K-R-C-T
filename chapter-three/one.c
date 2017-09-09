#include <stdio.h>
#include <limits.h>

/*
 * Exercise 3-1 of The C Programming Language
 *
 * Our binary search makes two tests inside the loop, when one would suffice
 * (at the price of more tests outside). Write a version with only one test
 * inside the loop and measure the difference in run-time.
 */

int binsearch(int x, int v[], int n);

int main(int argc, char **argv)
{
	// return '2' (x) from the array where n is the length of the array
	//NOTE: HOW DO YOU MAKE arr[] 'char **argv' WHEN IT'S AN INT?
	int arr[]={1,2,3,5,13};
	int x = 2;
	int n = 4;
  printf("%d\n",binsearch(x, arr, n));
	return 0;
}

/* One test inside loop */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low + high) / 2;

	while (low <= high && ! v[mid]) {
		if (x <= v[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	/* at the price of more tests outside */
	if (x == v[mid]) {
		return mid;
	}
	else {
		return -1; /* no match */
	}
}
