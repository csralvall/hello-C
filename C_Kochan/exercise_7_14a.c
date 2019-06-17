// This is exercise "7.14a" of the book "Programming in C" by Stephen G. Kochan.

// Program to sum all the elements in an array.
// Global Variables instead of arguments.

#include <stdio.h>

#define LENGTH	10

// Defining the global array.

int	array[LENGTH];

int main (void)
{
	int arraySum (void);

	printf	("Fill the array: \n");

	printf	("The sum of the elements of the array is: %i.\n", arraySum());
	return 0;
}


// Function to sum all the elements.

int arraySum (void)
{
	int	sum = 0;
	for ( int i = 0; i < LENGTH; ++i ) {
		printf	("What number do you want to store here? ---> [%i] = \n", i);
		scanf	("%i", &array[i]);
		sum += array[i];
	}
	return sum;
}
