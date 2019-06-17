// This is program 7.11 of the book "Programming in C" by Stephen G. Kochan.

// Program to sum all the elements in an array.

#include <stdio.h>

// Function to calculate the sum of all the elements in an array.

int arraySum (int array[], int size)
{
	int	sum;

	for ( int i = 0; i < size; ++i ) {
		printf	("Element %i: ", i);
		scanf	("%i", &array[i]);
		sum += array[i];
	}

	return sum;
}

// MAIN FUNCTION.

int main (void)
{
	int 	arraySum (int array[], int size);
	int 	n;

	printf	("Insert the number of elements of the array: ");
	scanf	("%i", &n);

	int 	sampleArray[n];

	printf	("The sum of all the elements in the array is equal to: %i.\n", arraySum(sampleArray, n));

	return 0;
}
