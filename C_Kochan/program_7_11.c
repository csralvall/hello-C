// This is program 7.11 of the book "Programming in C" by Stephen G. Kochan.

// Changing Array Elements in Functions.

#include <stdio.h>

void multiplyBy2 (float array[], int n)
{
	int i;

	for ( i = 0; i < n; ++i )
		array[i] *= 2;
}

int main (void)
{
	float	floatVals[4] = { 1.2f, -3.7f, 6.2f, 8.55f };
	int	i;
	void	multiplyBy2 (float array[], int n);

	multiplyBy2 (floatVals, 4);

	for ( i = 0; i < 4; ++i )
		printf	("%.2f\t", floatVals[i]);

	printf	("\n");

	return 0;
}
