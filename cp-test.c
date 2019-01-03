#include <stdio.h>

/* copy input to output; like a text processor */

int main()
{
	int c;

	while (c = (getchar() != EOF))
		putchar(c);
}
