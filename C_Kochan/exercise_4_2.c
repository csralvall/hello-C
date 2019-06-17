// This is exercise 4.1 of the book "Programming in C" by Stephen G. Kochan.

// This program display a table of n and "n^2" with their headings.

#include <stdio.h>

int main (void)
{
	int n, square;

	printf	("\n  TABLE OF SQUARES\n\n");
	printf	("Number	       Square\n");
	printf	("------	     -----------\n");

	for ( n = 1; n <= 10; ++n ) {
		square = n * n;
		printf (" %2i		%3i\n", n, square);
	}

	return 0;
}
