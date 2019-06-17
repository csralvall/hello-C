// This is exercise "7.2B" of the book "Programming in C" by Stephen G. Kochan.

// This program displays 5 triangular numbers of your desire.

#include <stdio.h>

int main (void)
{
	int	number, counter;
	int	calculateTriangularNumber (int n);
	
	for ( counter = 1; counter <= 5; ++counter ) {
		printf	("What triangular number do you want? ");
		scanf	("%i", &number);

		printf ("Triangular number %i is %i.\n\n", number, calculateTriangularNumber(number));
	}

	return 0;
}

// Function to calculate the nth triangular number.

int calculateTriangularNumber (int number)
{
	int i, triangularNumber = 0;

	for ( i = 1; i <= number; ++i )
		triangularNumber += i;

	return triangularNumber;
}
