// This is exercise 5.2 of the book "Programming in C" by Stephen G. Kochan.

// This program determine if one number is evenly divisible by other.

#include <stdio.h>

int main (void)
{
	int	value1, value2;

	printf	("Please, type two numbers: ");
	scanf	("%i %i", &value1, &value2);

	while ( value2 == 0 ) {
		printf	("The second value can't be zero, please, change it: ");
		scanf	("%i", &value2);
	}

	if ( (value1 % value2) == 0 )
		printf	("The first number is evenly divisible by the second.\n");
	else
		printf	("The first numbers isn't evenly divisible by the second.\n");

	return 0;
}
