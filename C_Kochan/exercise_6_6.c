// This is exercise 6.6 of the book "Programming in C" by Stephen G. Kochan.

// Generating Fibonacci Numbers without using any array.
// This is a modification of the program 6.3 of the same book.

#include <stdio.h>

int main (void)
{
	int	Fib, Fib1, Fib2, i; 
	
	// Initializing the first two Fibonacci numbers. And clearing the value of the desired Fibonacci number.
	
	Fib = Fib1 = 0;
	Fib2 = 1;

	// Printing the two first Fibonacci numbers.
	
	printf	("%i\n%i\n", Fib1, Fib2);

	for ( i = 2; i < 15; ++i ) {
		Fib = Fib1 + Fib2;
		Fib1 = Fib2;
		Fib2 = Fib;
		printf	("%i\n", Fib);
	}

	return 0;
}
