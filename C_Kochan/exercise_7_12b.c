// This is (an experiment of) exercise "7.12b" of the book "Programming in C" by Stephen G. Kochan.

// Program to transpose a matrix.

#include <stdio.h>

int	g_nRows;
int	g_nCols;

// Function to transpose a matrix.

void	transposeMatrix (int matrix1[g_nRows][g_nCols], int matrix2[g_nCols][g_nRows])
{
	int 	row, column;

	for ( row = 0; row < g_nRows; ++row )
		for ( column = 0; column < g_nCols; ++column )
			matrix2[column][row] = matrix1[row][column];
}

// Function to display a matrix on the screen.

void displayMatrix (int matrix[g_nRows][g_nCols])
{
	int	row, column;
	
	for ( row = 0; row < g_nRows; ++row ) {
		printf	("\t");
		for ( column = 0; column < g_nCols; ++column )
			printf	("%i ", matrix[row][column]);
		printf("\n");
	}
}

// Function to fill a matrix.

void fillMatrix (int matrix[g_nRows][g_nCols])
{
	int	row, column;
	char	options;
	
	printf	("Type A if you want to create a blank matrix, automatically.\n");
	printf	("Type anything else if you want to fill your matrix manually.\n");
	scanf	(" %c", &options);
	printf	("\n");
	
	if ( options == 'A' ) {
		for ( row = 0; row < g_nRows; ++row )
			for ( column = 0; column < g_nCols; ++column )
				matrix[row][column] = 0;
		printf	("\n");
	}else {
		for ( row = 0; row < g_nRows; ++row )
			for ( column = 0; column < g_nCols; ++column ) {
				printf	("Set the entry--> matrix[%i][%i]: ", row, column);
				scanf	("%i", &matrix[row][column]);
			}
		printf	("\n");
	}
}

// MAIN FUNCTION.

int main (void)
{
	void 	displayMatrix (int matrix[g_nRows][g_nCols]);
	void	transposeMatrix (int matrix1[g_nRows][g_nCols], int matrix2[g_nCols][g_nRows]);
	void	fillMatrix (int matrix[g_nRows][g_nCols]);
	
	printf	("\nPlease, set the size of the matrix that you want to create.\n");
	printf	("Rows: ");
	scanf	("%i", &g_nRows);
	printf	("Columns: ");
	scanf	("%i", &g_nCols);

	int	initialMatrix[g_nRows][g_nCols];
	int	blankMatrix[g_nRows][g_nCols];
	
	// Filling both matrix.

	printf	("Filling the matrix to transpose: \n\n");
	fillMatrix(initialMatrix);


	printf	("Filling the blank matrix: \n\n");
	fillMatrix(blankMatrix);

	// Displaying both matrix.
	
	printf	("Matrix to transpose: \n");
	displayMatrix (initialMatrix);

	printf	("Blank matrix: \n");
	displayMatrix (blankMatrix);

	// Transposing the initial matrix into the blank matrix.
	
	transposeMatrix (initialMatrix, blankMatrix);

	// Printing the transpose matrix (former blank matrix).
	
	printf	("Transpose Matrix: \n");
	displayMatrix (blankMatrix);

	return 0;
}
