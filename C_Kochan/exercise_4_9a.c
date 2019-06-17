// This is the exercise "4.9a" of the book "Programming in C" by Stephen G. Kochan.

/* Program to calculate the 200th triangular number
 * Introduction of the for statement. */

#include <stdio.h>

int main (void)
{
	// Declaration of variables.
	int	n, triangularNumber;

	// Initialization of variables.
	triangularNumber = 0;
	n = 1;

	// Statements and body of the program.
	while ( n <= 200 ) {
		triangularNumber = triangularNumber + n;
		n = n + 1;
	}

	// Output.
	printf ("The 200th triangular number is %i.\n", triangularNumber);

	return 0;
}
