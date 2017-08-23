#include <stdio.h>

/*
 * Exercise 1-3 of The C Programming Language
 *
 * Modify the temperature conversion program to print a heading above the table.
 */

 int main()
 {
  int coldest = 0;
  float fht = coldest;
  int hottest = 300;
  int inc = 20; /* increment by 20 */
  printf("Farenheight\t | \tCelsius\n");
  while (fht <= hottest) {
    float cel = (5.0/9.0) * (fht-32.0); /* perform celsius conversion */
    printf("%3.0f\t\t | \t%6.1f \n", fht, cel);
    fht = fht + inc;
  }
}
