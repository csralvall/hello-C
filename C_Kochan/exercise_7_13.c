// This is exercise 7.13 of the book "Programming in C" by Stephen G. Kochan.

// Program to sort an array in the prefered order (ascending or descending).

#include <stdio.h>

void sort (int a[], int n, char order)
{
	int	i, j, temp;

	switch (order)
	{
		case 'A':
			for ( i = 0; i < n - 1; ++i )
				for ( j = i + 1; j < n; ++j )
					if ( a[i] > a[j] ) {
						temp = a[i];
						a[i] = a[j];
						a[j] = temp;
					}
			break;
		case 'D':
			for ( i = 0; i < n - 1; ++i )
				for ( j = i + 1; j < n; ++j )
					if ( a[i] < a[j] ) {
						temp = a[i];
						a[i] = a[j];
						a[j] = temp;
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
	int 	array[16] = { 34, -5, 6, 0, 12, 100, 56, 22,
			      44, -3, -9, 12, 17, 22, 6, 11 };
	void 	sort (int a[], int n, char order);

	printf	("The array before the sort:\n");

	for ( i = 0; i < 16; ++i )
		printf	("%i ", array[i]);
	
	do {
		printf	("\n\nPlease, select the kind of sort that you want to perform.\n");
		printf	("Ascending (press A) or descending (press D):\n");
		scanf	(" %c", &order);
	}
	while ( order != 'A' && order != 'D' ); 

	sort (array, 16, order);

	printf	("\nThe array after the sort:\n");

	for ( i = 0; i < 16; ++i )
		printf	("%i ", array[i]);

	printf	("\n");

	return 0;
}
