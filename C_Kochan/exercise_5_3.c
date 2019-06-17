// This is exercise 5.3 of the book "Programming in C" by Stephen G. Kochan.

/* This program divides two numbers and displays the result with 
* three-decimal-place accuracy. */

#include <stdio.h>

int main (void)
{
	int	num1, num2; 
	float	result;

	printf	("Write two integer numbers: ");
	scanf	("%i %i", &num1, &num2);

	while ( num2 == 0 ) {
		printf	("The second number cant't be zero, please choose another one: ");
		scanf	("%i", &num2);
	}

	result = (float) num1 / num2;

	printf	("The result of divide the first number by the second is: %.3f.\n", result);

	return 0;
}
