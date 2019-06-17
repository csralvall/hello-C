// This is exercise 7.3 of the book "Programming in C" by Stephen G. Kochan.

// Function to calculate the absolute value of a number.

#include <stdio.h>

float absoluteValue (float x)
{
	if ( x < 0 )
		x = -x;

	return (x);
}

// Function to compute the square root of a number.

float squareRoot (float x, float epsilon)
{
	float		guess	= 1.0;

	while ( absoluteValue (guess * guess - x) >= epsilon )
		guess = ( x / guess + guess ) / 2.0;

	return guess;
}

int main (void)
{
	float	number, accuracy;
	for ( int i = 0; i < 4; ++i ) {
		printf	("Type the number and the accuracy: ");
		scanf	("%f %f", &number, &accuracy);
		printf	("squareRoot (%f) = %f\n", number, squareRoot (number, accuracy));
	}

	return 0;
}
