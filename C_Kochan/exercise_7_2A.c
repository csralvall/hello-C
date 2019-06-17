// This is exercise "7.2A" of the book "Programming in C" by Stephen G. Kochan.

// Function to calculate the nth triangular number.

#include <stdio.h>

int calculateTriangularNumber (int n)
{
	int i, triangularNumber = 0;
	
	for ( i = 1; i <= n; ++i )
		triangularNumber += i;

	return triangularNumber;
}

int main (void)
{
	printf	("Triangular number 10 is %i\n", calculateTriangularNumber(10));
	printf	("Triangular number 10 is %i\n", calculateTriangularNumber(20));
	printf	("Triangular number 10 is %i\n", calculateTriangularNumber(50));

	return 0;
}
