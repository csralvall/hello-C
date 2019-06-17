// This is exercise 4.11 of the book "Programming in C" by Stephen G. Kochan.

// This program calculate the sum of the digits of an integer.

#include <stdio.h>

int main (void)
{
	int number, sum;

	printf	("Insert a number: ");
	scanf	("%i", &number);

	sum = 0;

	do {
		sum = number % 10 + sum;
		number /= 10;
	}
	while ( number != 0 );
	
	printf	("The sum of the digits of the number is: %i.\n", sum);

	return 0;
}
