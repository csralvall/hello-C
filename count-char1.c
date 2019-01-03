#include <stdio.h>

/* count characters in input; 2nd version */

int main()
{
	double nc;

	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("\n%.0f\n", nc);
}
