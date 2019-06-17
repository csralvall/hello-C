// This is program 6.8 of the book "Programming in C" by Stephen G. Kochan.

// Generate Fibonacci numbers using variable length arrays.

#include <stdio.h>

int main (void)
{
	int	i, numFibs;

	printf	("How many fibonacci numbers do yoy want (between 1 and 75)? ");
	scanf	("%i", &numFibs);

	if (numFibs < 1 || numFibs > 75) {
		printf	("Bad number, sorry!\n");
		return 1;
	}

	unsigned long long int	Fibonacci[numFibs];

	Fibonacci[0] = 0;	// by definition
	Fibonacci[1] = 1;	// ditto

	for ( i = 2; i < numFibs; ++i )
		Fibonacci[i] = Fibonacci[i-2] + Fibonacci[i-1];

	for ( i = 0; i < numFibs; ++i )
		printf	("%llu  ", Fibonacci[i]);
	
	printf	("\n");

	return 0;
}
