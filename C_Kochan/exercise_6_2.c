// This is exercise 6.2 of the book "Programming in C" by Stephen G. Kochan.

// Working with an Array.
// Initializing all their values to zero with a for loop.
// (It could be do easiliy only initializing the first value to zero).

#include <stdio.h>

int main (void)
{
	int	values[10];
	int	index;

	for ( index = 0; index < 10; ++index )
		values[index] = 0;

	for ( index = 0; index < 10; ++index)
		printf	("values[%i] = %i\n", index, values[index]);

	return 0;
}
