#include <stdio.h>

/* replace each string of prevs by only one prev */

int main(){
	int c, prev;

	prev = 0;
	while ((c = getchar()) != EOF){
		if ((c != ' ')||(prev != ' '))
			putchar(c);
		prev = c;
	}
}
