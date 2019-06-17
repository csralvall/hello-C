// This is exercise "4.9c" of the book "Programming in C" by Stephen G. Kochan.

// This program calculates the triangular number that you desire.

#include <stdio.h>

int main (void)
{
	// Declaration of variables
	int n, number, triangularNumber;

	// Asking for input
	printf	("What triangular number do you want? ");
	scanf	("%i", &number);

	// Initialazing the variables
	triangularNumber = 0;
	n = 1;
	
	// The statements/routine
	while ( n <= number ) {
		triangularNumber += n;
		++n;
	}

	// The output
	printf ("Triangular number %i is %i.\n", number, triangularNumber);

	return 0;
}
