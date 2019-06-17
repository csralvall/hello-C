// This is exercise 7.8 of the book "Programming in C" by Stephen G. Kochan.

// Program to solve a quadratic equation with real roots.

#include <stdio.h>

// Declaring global variables.

long double	gRoot1, gRoot2;

// Function to calculate the absolute value of a number.

float absoluteValue (float x)
{
	if ( x < 0 )
		x = -x;

	return (x);
}

// Function to compute the square root of a number.

double squareRoot (long double x)
{
	const double	epsilon	= .0001;
	float		guess	= 1.0;
	
	while ( absoluteValue (guess * guess / x - 1) >= epsilon )
		guess = ( x / guess + guess ) / 2.0;

	return guess;
}

// Function to calculate the roots of a quadratic equation.

long double baskara (double a, double b, double c)
{
	long double	discriminant;

	discriminant = b * b - 4 * a * c;
	
	if ( discriminant >= 0 ) {
		gRoot1 = (-b + squareRoot(discriminant)) / (2 * a);
		gRoot2 = (-b - squareRoot(discriminant)) / (2 * a);
	}

	return discriminant;
}

// Main routine.

int main (void)
{
	double		a, b, c;
	float		absoluteValue (float x);
	double		squareRoot (long double x);
	long double	discriminant (double a, double b, double c);

	printf	("This program calculate the two posible solutions of a quadratic equation.\n");
	printf	("A quadratic equation has the following form: a(x^2) + bx + c = 0.\n");
	printf	("Please insert the values of the a, b, and c constants:\n");
	scanf	("%lf %lf %lf", &a, &b, &c);

	if ( baskara (a,b,c) < 0 ) 
		printf	("The solutions to the quadratic equation belongs to the imaginary set.\n");
	else {
		printf	("The solutions to the quadratic equation %f(x^2) + (%fx) + (%f) = 0 are: \n",
				a, b, c);
		printf	("\nFirst Root = %Lf\tSecond Root = %Lf.\n", gRoot1, gRoot2);
	}

	return 0;
}
