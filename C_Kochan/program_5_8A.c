// This is program "5.8A" of the book "Programming in C" by Stephen G. Kochan.

/* Program to evaluate simple expressions of the form number operator number.
 * 2th version. */

#include <stdio.h>

int main (void)
{
	float	value1, value2;
	char	operator;

	printf	("Type in you expression.\n");
	scanf	("%f %c %f", &value1, &operator, &value2);

	if ( operator == '+' )
		printf	("%.2f\n", value1 + value2);
	else if ( operator == '-' )
		printf	("%.2f\n", value1 - value2);
	else if ( operator == '*' )
		printf	("%.2f\n", value1 * value2);
	else if ( operator == '/' )
		if ( value2 == 0)
			printf	("Division by zero.\n");
		else
			printf	("%.2f\n", value1 / value2);
	else
		printf	("Unknown operator.\n");

	return 0;
}
