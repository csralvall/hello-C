// This is exercise 4.8 of the book "Programming in C" by Stephen G. Kochan.

// This program allows the user to calculate as many triangular numbers as he needs.

#include <stdio.h>

int main (void)
{
	int n, number, triangularNumber, counter, how_many;

	printf	("How many triangular numbers do you want to calculate?, type it: \n");
	scanf	("%i", &how_many);

	for ( counter = 1; counter <= how_many; ++counter ) {
		printf	("What triangular number do you want? ");
		scanf	("%i", &number);

		triangularNumber = 0;

		for ( n = 1; n <= number; ++n )
			triangularNumber += n;

		printf ("Triangular number %i is %i.\n\n", number, triangularNumber);
	}

	return 0;
}
