// This is exercise 6.4 of the book "Programming in C" by Stephen G. Kochan.

// This program calculates the average of an array.

#include <stdio.h>

int main (void)
{
	float	array[10], sum = 0;

	printf	("Insert the ten values: \n");

	for ( int i = 0; i < 10; ++i ) {
		scanf	("%g", &array[i]);
		sum += array[i];
	}

	printf	("\nThe average of the array is %g\n", sum / 10);

	return 0;
}
