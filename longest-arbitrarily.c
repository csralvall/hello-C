#include <stdio.h>
#define MAXLINE	1000	/* maximum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */

int main()
{
	int len;		/* current line length */
	int max;		/* maximum length seen so far */
	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if(max > 0) {		/*there was a line */
		printf("%s", longest);
		printf("\n\nThe longest line has %d characters.\n", max);
	}
	return 0;
}

/* getline: read a line into s, return length even if it is bigger than MAXLINE */

int getline(char s[], int lim)
{
	int c, i, r;

	for (i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	r = i;
	while ((c = getchar()) != '\n' && c != EOF) 
		++i;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[r] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
