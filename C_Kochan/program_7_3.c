// This is program 7.3 of the book "Programming in C" by Stephen G. Kochan.

// More on Calling Functions.
// Introducing a second modification to program 7.1.

#include <stdio.h>

void printMessage (void)
{
	printf	("Programming is fun.\n");
}

int main (void)
{
	int	i;
	for ( i = 1; i <= 5; ++i)
		printMessage ();

	return 0;
}
