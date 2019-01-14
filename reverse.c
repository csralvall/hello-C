#include <stdio.h>
#define MAXLENGTH	3000	/* permited size of lines */

int reverse(char s[], int l);
void copy(char to[], char from[], int c);

/* print the line with the characters reversed */

int main()
{
	int len = 0;		/* size of the line */
	char input[MAXLENGTH];	/* where is saved the reversed line */ 
	char output[MAXLENGTH];	/* helps to print the reversed line */ 
	
	if((len = reverse(input,MAXLENGTH)) > 0)
		copy(output, input, len);
	printf("\nThe reversed line is: %s", output);
}

/* take a character and save it in an array in the opposite of the common way */

int reverse(char line[], int length)
{
	int c, i;

	i = 0;
	for(i = length-2; (c = getchar()) != EOF && c != '\n'; --i)
		line[i] = c;
	if (c == '\n') {
		line[length-1] = c;
		++i;
	}
	line[length] = '\0';
	return i;
}

/* copy characters in the same order without the unused access of the array */

void copy (char to[], char from[], int len)
{
	for (int i = 0; (to[i] = from[len+i]) != '\0'; ++i)
		;
}
