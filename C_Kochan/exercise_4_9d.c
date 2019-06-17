// This is exercise "4.9d" of the book "Programming in C" by Stephen G. Kochan.

// This program calculates the 5 triangular numbers that you want.

#include <stdio.h>

int main (void)
{
	int n, number, triangularNumber, counter;

	counter = 1;

	while ( counter <= 5 ) {
		printf	("What triangular number do you want? ");
		scanf	("%i", &number);

		triangularNumber = 0;
		n = 1;

		while ( n <= number ) {
			triangularNumber += n;
			++n;
		}

		printf ("Triangular number %i is %i.\n\n", number, triangularNumber);
	}
		
	return 0;
}
