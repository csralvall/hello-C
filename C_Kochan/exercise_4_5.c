// This is exercise 4.5 of the book "Programming in C" by Stephen G. Kochan.

// The objective of this exercise is to correct the format of the program.

// The program indeed display a table of powers of two.

#include <stdio.h>

int main (void)
{
	int n, two_to_the_n;

	printf	("TABLE OF POWERS OF TWO\n\n");
	printf	(" n	   2 to the n\n");
	printf	("---	 ---------------\n");

	two_to_the_n = 1;

	for ( n = 0; n <= 10; ++n) {
		// Right justification
		printf	("%2i		%i\n", n, two_to_the_n);
		two_to_the_n *= 2;
	}

	return 0;
}
