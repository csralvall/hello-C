#include <stdio.h>

/* count blanks, tabs and newlines */

int main()
{
	int c, nl, nt, nb;

	nl = 0;
	nt = 0;
	nb = 0;
	while ((c = getchar()) != EOF){
		if (c == '\n'){
			++nl;
		}else if (c == '\t'){
			++nt;
		}else if (c == ' '){
			++nb;
		}
	}
	printf("\n%d, %d, %d\n", nl, nt, nb);
}
