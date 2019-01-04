#include <stdio.h>

/* copy the intput to its output replacing each hidden character by its visible "mode" */

int main()
{
	int c;

	while ((c = getchar()) != EOF){
		if (c == '\t'){
			printf("\\t");
		}else if (c == '\b'){
			printf("\\b");
		}else if (c == '\\'){
			printf("\\\\");
		}else{
			putchar(c);
		}
	}
	return 0;
}
