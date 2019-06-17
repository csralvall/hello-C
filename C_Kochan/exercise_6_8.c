// This is exercise 6.8 of the book "Programming in C" by Stephen G. Kochan.

// Generating prime numbers with the Sieve of Eratosthenes.
// Modified program to demonstrate the use of variable size arrays.

#include <stdio.h>

int main (void)
{
	int	n, i;

	do {
		printf	("You want all prime numbers between zero and...(Positive number)?: \n");
		scanf	("%i", &n);
		if ( n < 0 )
			printf	("Sorry, positive numbers only.\n");
	}
	while ( n < 0 );

	// Initializing the array with the variable size of n.

	int	prime[n];

	for ( i = 2; i < n; ++i )
		prime[i] = 0;

	for ( i = 2; i <= n; ++i )
		for ( int j = 2; j * i < n; ++j )
			prime[j*i] = 1;
	
	for ( i = 0; i < n; ++i )
		if ( prime[i] == 0 )
			printf	("%i\n", i);

	return 0;
}
