/* This is the program 4.1 of the book
 * "Programming in C" by Stephen G. Kochan. */

// Program to calculate the eight triangular number.

#include <stdio.h>

int main (void)
{
	int	triangularNumber;

	triangularNumber = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8;

	printf ("The eighth triangular number is %i.\n", triangularNumber);

	return 0;
}
