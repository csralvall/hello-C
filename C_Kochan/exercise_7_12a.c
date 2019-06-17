// This is exercise "7.12a" of the book "Programming in C" by Stephen G. Kochan.

// Program to transpose a matrix.

#include <stdio.h>

// Function to transpose a matrix.

void transposeMatrix (int matrix1[4][5], int matrix2[5][4])
{
	int 	row, column;

	for ( row = 0; row < 4; ++row )
		for ( column = 0; column < 5; ++column )
			matrix2[column][row] = matrix1[row][column];
}

// Function to display a matrix on the screen.

void displayMatrix (int nRows, int nCols, int matrix[nRows][nCols])
{
	int	row, column;
	
	for ( row = 0; row < nRows; ++row ) {
		printf	("\t");
		for ( column = 0; column < nCols; ++column )
			printf	("%i ", matrix[row][column]);
		printf("\n");
	}
}

// MAIN FUNCTION.

int main (void)
{
	int	initialMatrix[4][5] =
					{
						{ 1, 2, 2, 2, 2},
						{ 3, 1, 2, 2, 2},
						{ 3, 3, 1, 2, 2},
						{ 3, 3, 3, 1, 2}
					};
	int	blankMatrix[5][4] = { 0 };
	void 	displayMatrix (int nRows, int nCols, int matrix[nRows][nCols]);
	void	transposeMatrix (int matrix1[4][5], int matrix2[5][4]);

	// Displaying both matrix.
	
	printf	("Matrix to transpose: \n");
	displayMatrix (4, 5, initialMatrix);

	printf	("Blank matrix: \n");
	displayMatrix (5, 4, blankMatrix); // Proving initialization of arrays.

	// Transposing the matrix.
	
	transposeMatrix (initialMatrix, blankMatrix);

	// Printing the transpose matrix.
	
	printf	("Transpose Matrix: \n");
	displayMatrix (5, 4, blankMatrix);

	return 0;
}

