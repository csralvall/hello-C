/* This is the exercise 3.9 of the book
 * "Programming in C" by Stephen G. Kochan. */

// This program finds the next largest even multiple of the written numbers.

#include <stdio.h>

int main (void)
{
	int i, j;
	
	// The expression i + j - i % j represents the next even multiple.
	
	i = 365;
	j = 7;
	printf ("The next largest even multiple between %i and %i is %i.\n", i, j, i + j - i % j);

	i = 12258;
	j = 23;
	printf ("The next largest even multiple between %i and %i is %i.\n", i, j, i + j - i % j);

	i = 996;
	j = 4;
	printf ("The next largest even multiple between %i and %i is %i.\n", i, j, i + j - i % j);

	return 0;
}
