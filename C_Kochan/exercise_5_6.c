// This continueis exercise 5.6 of the book "Programming in C" by Stephen G. Kochan.

// Program to write in english each digit keyed in form the terminal.

#include <stdio.h>

int main (void)
{
	int number, duplicate, exp, zero;

	printf	("Type a integer number: ");
	scanf	("%i", &number);
	
	duplicate = number; // To keep the track of what digit should be printed.
	zero = 0;
	
	do {
		exp = 1;	
		for ( int n = 0; number >= 10; ++n ) {
			if ( number % 10 == 0 )
				++zero; // To count how many zero's are between digits and next to them.
			else
				zero = 0; // When you find a number that isn't even divisible by 10 you throw the count.
			number /= 10;
			exp *= 10; // This will help us to actualize the "duplicate" variable.
		}

		// printing

		switch ( number ) {
			case 0:
				printf	("zero ");
				break;
			case 1:
				printf	("one ");
				break;
			case 2:
				printf	("two ");
				break;
			case 3:
				printf	("three ");
				break;
			case 4:
				printf	("four ");
				break;
			case 5:
				printf	("five ");
				break;
			case 6:
				printf	("six ");
				break;
			case 7:
				printf	("seven ");
				break;
			case 8:
				printf	("eight ");
				break;
			case 9:
				printf	("nine ");
				break;
			default:
				break;
		}

		// printing zero's if there is anyone.

		for ( int n = 0; n < zero; ++n)
			printf	("zero ");
		duplicate -= number * exp; // Taking down the already printed number.
		number = duplicate; // Updating the original number.
		zero = 0; // Reseting the zero count.
	} while ( number != 0 );

	printf	("\n");

	return 0;
}
