// This is exercise 7.7 of the book "Programming in C" by Stephen G. Kochan.

// Program to raise an integer to a positive integer power.

#include <stdio.h>

long int x_to_the_n (int base, int exponent)
{
	long int result = 1;

	for (int i = 0; i < exponent; ++i)
		result *= base;

	return result;
}

int main (void)
{
	int base, exponent;
	long int x_to_the_n (int base, int exponent);

	printf	("Type the base and the exponent: ");
	scanf	("%i %i", &base, &exponent);
	
	if ( exponent < 0 ) {
		printf	("Exponents must be positive.\n");
		return 1;
	}

	printf	("\n%i to the %i is %li\n", base, exponent, x_to_the_n (base, exponent));

	return 0;
}
