// This is exercise 4.4 of the book "Programming in C" by Stephen G. Kochan.

// This program displays a table of the first ten numbers and their factorials.

#include <stdio.h>

int main (void)
{
	int number, factorial;

	printf	("\n  TABLE OF FACTORIALS\n\n");
	printf	("Number\t\tFactorial\n");
	printf	("------\t\t---------\n");

	factorial = 1;

	for ( number = 1; number <= 10; ++number ) {
		factorial = number * factorial;
		printf	(" %2i\t\t   %i\n", number, factorial);
	}

	return 0;
}
