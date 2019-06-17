// This is exercise 5.7 of the book "Programming in C" by Stephen G. Kochan.

// Program to generate a table of prime numbers.
// Avoiding the ineficiencies of the program 5.10.

#include <stdio.h>

int main (void)
{
	int	p, d;
	_Bool	isPrime;
	
	printf ("2\t");

	for ( p = 3; p <= 50; p += 2 ) {
		isPrime = 1;

		for ( d = 3; d < p && isPrime; d += 2 )
			if ( p % d == 0 )
				isPrime = 0;

		if ( isPrime != 0 )
			printf ("%i\t", p);
	}

	printf	("\n");
	return 0;
}
