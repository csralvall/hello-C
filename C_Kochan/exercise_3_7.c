/* This is the exercise 7 of the chapter 3 of the book
 * "Programming with C" by Stephen G. Kochan */

// This program evaluates the expression write it.

#include <stdio.h>

int main (void)
{
	float a = 3.31e-8;
	float b = 2.01e-7;
	float c = 7.16e-6;
	float d = 2.01e-8;

	printf ("a = %e, b = %e, c = %e, d = %e.\n", a, b, c, d);
	printf ("(a * b) / (c * d) = %e.\n", (a * b) / (c + d));

	return 0;
}

