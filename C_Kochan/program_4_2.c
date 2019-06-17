/* This is the program 4.2 of the book
 * "Programming in C" by Stephen G. Kochan. */

/* Program to calculate the 200th triangular number
 * Introduction of the for statement. */

#include <stdio.h>

int main (void)
{
	// Declaration of variables.
	int	n, triangularNumber;

	// Initialization of variables.
	triangularNumber = 0;

	// Statements and body of the program.
	for ( n = 1; n <= 200; n = n + 1)
		triangularNumber = triangularNumber + n;

	// Output.
	printf ("The 200th triangular number is %i.\n", triangularNumber);

	return 0;
}
