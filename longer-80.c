#include <stdio.h>

#define MAXLINE		1000	/* maximum input line size */
#define CUTOFF		80	/* minimum of characters to admit */
#define MAXOUTPUT	65000	/* maximum of lines to be printed */

int getline(char line[], int maxline);
void copy(char to[], char from[], int r);

/* print longest input line */

int main()
{
	int len;			/* current line length */
	int last;
	char line[MAXLINE];		/* current input line */
	char longest[MAXOUTPUT];	/* longest line saved here */

	last = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > CUTOFF) {
			copy(longest, line, last);
			last = last + len;
		}
	if(last > 0)			/*there was a line */
		printf("%s", longest);
	return 0;
}

/* getline: read a line into s, return length */

int getline(char s[], int lim)
{
	int c, i;

	for (i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */

void copy(char to[], char from[], int r)
{
	int i;

	i = 0;
	while ((to[i+r] = from[i]) != '\0')
		++i;
}
