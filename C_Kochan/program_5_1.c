// This is program 5.1 of the book "Programming in C" by Stephen G. Kochan.

// Program to claculate the absolute value of an integer.

#include <stdio.h>

int main (void)
{
	int	number;
	
	printf	("Type in your numbers: ");
	scanf	("%i", &number);

	if ( number < 0 )
		number = -number;

	printf	("The absolute value is %i\n", number);

	return 0;
}
