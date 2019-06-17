// This is exercise 7.10 of the book "Programming in C" by Stephen G. Kochan.

// Program that decide if a number is prime or not.

#include <stdio.h>

// Function to calculate the absolute value of a number.

float absoluteValue (float x)
{
	if ( x < 0 )
		x = -x;

	return (x);
}

// Function to compute the square root of a number.

float squareRoot (float number)
{
	const float	epsilon	= .00001;
	float		guess	= 1.0;	

	while ( absoluteValue (guess * guess - number) >= epsilon )
		guess = ( number / guess + guess ) / 2.0;

	return guess;
}

// Function to decide if a number is prime or not.

_Bool prime (int number)
{
	_Bool	isPrime = 1;
	int	i;

	if ( number == 1 )
		return isPrime;
	else if ( (number % 2) == 0 ) {
		isPrime = 0;
		return isPrime;
	}

	for ( i = 3; isPrime && i <= squareRoot((float) number); i += 2 )
		if ( number % i == 0 ) {
			isPrime = 0;
			break;
		}

	return isPrime;
}

int main (void)
{
	float	squareRoot (float number);
	_Bool	prime (int number);
	int	number;
	
	printf	("\nThis program will display a one if the number is prime and a zero if it isn't.\n");
	printf	("Please type the number that you want to analyse:\n");
	scanf	("%i", &number);

	printf	("The number is %i.\n", prime(number));

	return 0;
}
