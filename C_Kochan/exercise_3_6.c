/* This is the exercise 6 of the chapter 3 of the book
 * "Programming with C" by Stephen G. Kochan */

// This program evaluates a polynimial in a given value.

#include <stdio.h>

float pot (float base, int exponent);

int main (void)
{
	float value = 2.55;

	printf ("The polynomial 3 * X^3 - 5 * X^2 + 6 evaluated by the value %f is equal to %f.\n"
			, value, 3 * pot(value,3) - 5 * pot(value,2) + 6);

	return 0;
}

// The following function computates the potence of a given base in a given exponent.
float pot (float base, int exponent)
{
	float save = base;

	for (int i = 0; i < exponent - 1; ++i)
		base *= save;
	
	return base;
}
