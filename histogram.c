#include <stdio.h>

#define IN		1	/* inside a word */
#define OUT		0	/* outside a word */
#define MAX_WORD	1000	/* maximum of words */

/* print a histogram of the lenghts of words in its input */

int main()
{
	int c, i, nw, state;
	int lengths[MAX_WORD];

	nw = 0;
	state = OUT;
	for (i = 0; i <= MAX_WORD; ++i)
		lengths[i] = 0;
	while ((c = getchar()) != EOF && nw < MAX_WORD) {
		if (c == ' ' || c == '\t' || c == '\n')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
		if (state == IN)
			++lengths[nw];
	}
	printf("Histogram of the lenghts of the words in the input\n");
	printf("------------------------------------------------------------------------------\n");
	for (i = 1; i <= nw; ++i) {
		printf("%d", i);
		for (int x = 0; x <= lengths[i]; ++x)
			printf("|");
		printf("\n");
	}
	printf("------------------------------------------------------------------------------\n");
}

