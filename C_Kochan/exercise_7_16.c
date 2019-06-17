// This is exercise 7.16 of the book "Programming in C" by Stephen. G. Kochan.

// Program to convert a positive integer to another base.

#include <stdio.h>

int		convertedNumber[64];
long int	numberToConvert;
int		base;
int		digit = 0;

void	getNumberAndBase (void)
{
	printf	("Number to be converted? ");
	scanf	("%li", &numberToConvert);

	printf	("Base? ");
	scanf	("%i", &base);

	if ( base < 2 || base > 16 ) {
		printf	("Bad base - must be between 2 and 16\n");
		base = 10;
	}
}

void	convertNumber (void)
{
	do {
		convertedNumber[digit] = numberToConvert % base;
		++digit;
		numberToConvert /= base;
	}
	while ( numberToConvert != 0 );
}

void	displayConvertedNumber (void)
{
	const char	baseDigits[16] =
		{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	int	nextDigit;

	printf	("Converted number = ");

	for ( --digit; digit >= 0; --digit ) { // Pay attention here.
		nextDigit = convertedNumber[digit];
		printf ("%c", baseDigits[nextDigit]);
	}

	// Here the value of digits is now -1.
	// So if you repeat the process you are losing one digit each time that you execute the function.
	
	digit = 0; // Now, the value of the global variable is restored and the problem is solved.

	printf	("\n");
}

int	main (void)
{
	int	q;
	void	getNumberAndBase (void), convertNumber (void), displayConvertedNumber (void);
	
	printf	("How many numbers do you want to convert?\n");
	scanf	("%i", &q);

	for ( int i = 0; i < q; ++i ) {
		getNumberAndBase ();
		convertNumber ();
		displayConvertedNumber ();
	}

	
	return 0;
}
