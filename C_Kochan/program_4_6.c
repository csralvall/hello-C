// This is program 4.6 of the book "Programming in C" by Stephen G. Kochan.

// Program to introduce the while statement.

#include <stdio.h>

int main (void)
{
	int count = 1;

	while ( count <= 5 ) {
		printf ("%i\n", count);
		++count;
	}

	return 0;
}
