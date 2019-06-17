// This is program 4.9 of the book "Programming in C" by Stephen G. Kochan.

// Program to reverse the digits of a number using a "do loop".

#include <stdio.h>

int main (void)
{
	int	number, right_digit;

	printf	("Enter your number.\n");
	scanf	("%i", &number);

	do {
		right_digit = number % 10;
		printf ("%i", right_digit);
		number = number / 10;
	}
	while ( number != 0 );

	printf ("\n");

	return 0;
}
