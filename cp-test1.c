#include <stdio.h>

/* verifying what is the output of the expression getchar() != EOF */

int main()
{
	int c;

	while (c = getchar() != EOF)
		printf("%d\n",c);
}
