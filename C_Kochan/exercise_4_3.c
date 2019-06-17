// This is exercise 4.3 of the book "Programming in C" by Stephen G. Kochan.

/* This program calculates the triangular number from 5 to 50,
 * using the formula "n * ( n + 1 ) / 2" jumping by 5 numbers each time. */

#include <stdio.h>

int main (void)
{
	int n, triangularNumber;

	printf	("\nTABLE OF TRIANGULAR NUMBERS\n\n");
	printf	("Number\tTriangularNumber\n");
	printf	("------\t----------------\n");

	triangularNumber = 0;

	for ( n = 5; n <= 50; n += 5 ) {
		triangularNumber = n * (n + 1) / 2;
		printf	(" %2i\t\t%4i\n", n, triangularNumber);
	}

	return 0;
}
