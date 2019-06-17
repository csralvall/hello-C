// This is exercise "7.14c" of the book "Programming in C" by Stephen G. Kochan.

// Program to sort an array in the prefered order (ascending or descending).
// Using global arrays.

#include <stdio.h>

int 	g_array[16] = { 34, -5, 6, 0, 12, 100, 56, 22,
		      44, -3, -9, 12, 17, 22, 6, 11 };

void sort (char order)
{
	int	i, j, temp;

	switch (order)
	{
		case 'A':
			for ( i = 0; i < 15; ++i )
				for ( j = i + 1; j < 16; ++j )
					if ( g_array[i] > g_array[j] ) {
						temp = g_array[i];
						g_array[i] = g_array[j];
						g_array[j] = temp;
					}
			break;
		case 'D':
			for ( i = 0; i < 15; ++i )
				for ( j = i + 1; j < 16; ++j )
					if ( g_array[i] < g_array[j] ) {
						temp = g_array[i];
						g_array[i] = g_array[j];
						g_array[j] = temp;
					}
			break;
		default:
			break;
	}
}

int main (void)
{
	int	i;
	char	order;
	void 	sort (char order);

	printf	("The array before the sort:\n");

	for ( i = 0; i < 16; ++i )
		printf	("%i ", g_array[i]);
	
	do {
		printf	("\n\nPlease, select the kind of sort that you want to perform.\n");
		printf	("Ascending (press A) or descending (press D):\n");
		scanf	(" %c", &order);
	}
	while ( order != 'A' && order != 'D' ); 

	sort (order);

	printf	("\nThe array after the sort:\n");

	for ( i = 0; i < 16; ++i )
		printf	("%i ", g_array[i]);

	printf	("\n");

	return 0;
}
