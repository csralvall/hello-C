#include <stdio.h>

#define	RELATION	8	/* relation between tabs and blanks */
#define	LIMIT		1000	/* maximum size of a line */

int getline(char line[], int size);
void copy(char to[], char from[]);

int main()
{
	int length;
	char line[LIMIT];
	char output[LIMIT];

	length = 0;

	if ((length = getline(line, LIMIT)) > 0)
		copy(output, line);
	printf("%s\n", output);
	return 0;
}

int getline(char line[], int size)
{
	int c, i = 0;
	
	while (i < size-2 && (c = getchar()) != EOF && c != '\n') {
		if (c == '\t')
			if ((i % RELATION) == 0)
				for (int x = 0; x < RELATION; ++x) {
					line[i] = ' ';
					++i;
				}
			else
				for (int x = i; (x % RELATION) != 0; ++x) {
					line[i] = ' ';
					++i;
				}	
		else {
			line[i] = c;
			++i;
		}
	}
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
	}

void copy(char to[], char from[])
{
	int i = 0;

	while ((to[i] = from[i]) != '\0')
		++i;
}
