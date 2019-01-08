#include <stdio.h>

#define MAX_ASCII	200	/* maximum of ASCII code */

/* print a histogram of the frequencies of different characters */

int main()
{
	int c, i, lc, nc;
	int lengths[MAX_ASCII];

	lc = nc = 0;
	for (i = 0; i <= MAX_ASCII; ++i)
		lengths[i] = 0;
	while ((c = getchar()) != EOF && nc < MAX_ASCII) {
			++lengths[c];
			if (c > lc)
				lc = c;
	}
	printf("\n\t\tHistogram of frequencies of diferent characters\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	for (i = 0; i <= lc; ++i) 
		if (lengths[i] != 0) {
			if (i == ' ')
				printf("\\b");
			else if (i == '\t')
				printf("\\t");
			else if (i == '\n')
				printf("\\n");
			else
				putchar(i);
			printf("\t");
			for (int x = 0; x <= lengths[i]; ++x)
				printf("|");
			printf("\n");
		}
	
	printf("-------------------------------------------------------------------------------------------------\n");
}

