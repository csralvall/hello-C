// This is exercise 6.7 of the book "Programming in C" by Stephen G. Kochan.

// Generating prime numbers with the Sieve of Eratosthenes.

#include <stdio.h>

int main (void)
{
	int	prime[150] = { 0 }, i;

	// Initializing the first entry of the array to zero.
	// The rest of the array will be automaticaly set to zero.

	for ( i = 2; i < 150; ++i )
		for ( int j = 2; j * i < 150; ++j )
			prime[j*i] = 1;
	
	for ( i = 0; i < 150; ++i )
		if ( prime[i] == 0 )
			printf	("%i\n", i);

	return 0;
}
