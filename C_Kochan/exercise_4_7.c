// This is exercise 4.7 of the book "Programmin in C" by Stephen G. Kochan.

// This programs shows how many dollars do you enter in the input.

#include <stdio.h>

int main (void)
{
	int	dollars, cents, count;

	for ( count = 1; count <= 10; ++count) {
		printf	("Enter dollars: ");
		scanf	("%i", &dollars);
		printf	("Enter cents: ");
		scanf	("%i", &cents);
		printf	("$%i.%.2i\n\n", dollars, cents);
	}

	return 0;
}
