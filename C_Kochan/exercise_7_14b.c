// This is exercise "7.14b" of the book "Programming in C" by Stephen G. Kochan.

// Program to transpose a matrix.

#include <stdio.h>

// Declaring global arrays.

int	g_matrix1[4][5] =
				{
					{ 1, 2, 2, 2, 2},
					{ 3, 1, 2, 2, 2},
					{ 3, 3, 1, 2, 2},
					{ 3, 3, 3, 1, 2}
				};
int 	g_matrix2[5][4];

// Function to transpose a matrix.

void transposeMatrix (void)
{
	int 	row, column;

	for ( row = 0; row < 4; ++row )
		for ( column = 0; column < 5; ++column ) {
			g_matrix2[column][row] = g_matrix1[row][column];
			printf	("matrix2[%i][%i] = %i\n\n", column, row, g_matrix2[column][row]);
		}
}

// MAIN FUNCTION.

int main (void)
{
	int	row, column;
	int	g_matrix1[4][5] =
					{
						{ 1, 2, 2, 2, 2},
						{ 3, 1, 2, 2, 2},
						{ 3, 3, 1, 2, 2},
						{ 3, 3, 3, 1, 2}
					};
	void	transposeMatrix (void);

	// Displaying matrix to transpose.
	
	printf	("Matrix to transpose: \n");

	for ( row = 0; row < 4; ++row ) {
		printf	("\t");
		for ( column = 0; column < 5; ++column )
			printf	("%i ", g_matrix1[row][column]);
		printf("\n");
	}

	// Transposing the matrix.
	
	transposeMatrix();

	// Printing the transpose matrix.
	
	printf	("Transpose Matrix: \n");
	
	for ( row = 0; row < 5; ++row ) {
		printf	("\t");
		for ( column = 0; column < 4; ++column )
			printf	("%i ", g_matrix2[row][column]);
		printf("\n");
	}

	return 0;
}

