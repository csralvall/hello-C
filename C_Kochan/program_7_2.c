// This is program 7.2 of the book "Programming in C" by Stephen G. Kochan.

// Writing a function in C.
// Introducing a modification to the original code of program 7.1.

#include <stdio.h>

void printMessage (void)
{
	printf	("Programming is fun.\n");
}

int main (void)
{
	printMessage ();
	printMessage ();

	return 0;
}
