// This is program 4.4 of the book "Programming in C" by Stephen G. Kochan.

// This program shows the usage of the function "scanf" to insert input in a program.

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
	
	// The statements/routine
	for ( n = 1; n <= number; ++n)
		triangularNumber += n;

	// The output
	printf ("Triangular number %i is %i.\n", number, triangularNumber);

	return 0;
}
