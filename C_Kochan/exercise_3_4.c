/* This is the exercise 4 of the chapther 3 of the book
 * "Programming in C" by Stephen G. Kochan */

// converts 27 from Fahrenheit degrees to Celsius degrees

#include <stdio.h>

int main (void)
{
	int degree = 27;

	printf ("The temperature in Fahrenheit is equal to %i.\n", degree);
	printf ("The same temperature in Celsius is equal to %f.\n", (degree - 32) / 1.8);

	return 0;
}
