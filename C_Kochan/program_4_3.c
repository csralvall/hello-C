// This is program 4.3 of the book "Programming in C" by Stephen G. Kochan.

// Program to generate a table of triangular numbers.

#include <stdio.h>

int main (void)
{
	int n, triangularNumber;

	printf ("TABLE OF TRIANGULAR NUMBERS\n\n");
	printf (" n	Sum from 1 to n.\n");
	printf ("---	----------------\n");

	triangularNumber = 0;

	for ( n = 1; n <= 10; ++n ) {
		triangularNumber += n;
		printf (" %i		%i\n", n, triangularNumber);
	}

	return 0;
}
