// This is exercise 5.4 of the book "Programming in C" by Stephen G. Kochan.

/* Program that acts as a "printing" calculator. With the following operations
 * "+, *, -, /". */

#include <stdio.h>

int main (void)
{
	float	number, accumulator;
	_Bool	flagN, flagO;
	char	operator;

	printf	("\n\t\t\tSIMPLE PRINTING CALCULATOR\n\n");
	printf	("-----------------------------------------------------------------------------------------------\n");
	printf	("This calculator allows the following operations: +, -, *, /.\n");
	printf	("If you want set the initial number you have to insert S.\n");
	printf	("If you want to exit you have to insert E.\n\n\n");

	accumulator = 0;
	flagN = 0;
	flagO = 0;

	do {
		if ( !flagN ) {
			printf	("\nType a new number: ");
			scanf	("%g", &number);
			flagN = 1;
		}

		if ( !flagO ) {
			printf	("Type a valid operator: ");
			scanf	("%c", &operator);
			flagO = 1;
		}

		switch (operator) {
			case 'S':
				accumulator = number;
				printf	("= %g\n", accumulator);
				flagN = flagO = 0;
				break;
			case '+':
				accumulator += number;
				printf	("= %g\n", accumulator);
				flagN = flagO = 0;
				break;
			case '-':
				accumulator -= number;
				printf	("= %g\n", accumulator);
				flagN = flagO = 0;
				break;
			case '*':
				accumulator *= number;
				printf	("= %g\n", accumulator);
				flagN = flagO = 0;
				break;
			case '/':
				if (number == 0) {
					printf	("You can't divide by zero, please, enter another number.\n");
					flagN = 0;
				}else {
					accumulator /= number;
					printf	("= %g\n", accumulator);
					flagN = flagO = 0;
				}
				break;
			case 'E':
				printf	("End of calculations.\nFinal result: %g.\n", accumulator);
				break;
			default:
				printf	("This program doesn't have configured that operation.\n");
				flagO = 0;
				break;
		}
	} while ( operator != 'E' );

	return 0;
}
