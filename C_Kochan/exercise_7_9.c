// This is exercise 7.9 of the book "Programming in C" by Stephen G. Kochan.

// Function to find the least common multiple of two positive integers.

#include <stdio.h>

// Function to calculate the great common divisor of two positive numbers.

int gcd (int u, int v)
{
	int	temp;

	while ( v != 0 ) {
		temp = u % v;
		u = v;
		v = temp;
	}

	return u;
}

// Function to calculate the least common multiple of two numbers.
// With the help of the identity: lcm (u, v) = uv / gcd (u, v) --- u, v >= 0.

int lcm (int u, int v)
{
	int	result;

	result = ( u * v ) / gcd (u,v);
	
	return result;
}

int main (void)
{
	int	gcd (int u, int v);
	int 	lcm (int u, int v);
	int	u, v;

	printf	("Insert to numbers to calculate their least common multiple:\n");
	scanf	("%i %i", &u, &v);

	printf	("The least common multiple of the two numbers are: %i.\n", lcm(u,v));
	
	return 0;
}
