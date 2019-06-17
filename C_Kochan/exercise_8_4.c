// This is exercise 8.2 of the book "Programming in C" by Stephen G. Kochan.

// Program to calculate the in which day falls a determined date. 

#include <stdio.h>

// Declaring struct to store the date.

struct	date	// Don't forget the struct before the type.
{
	int	month;
	int	day;
	int	year;
};		// And the coma to finish the definition of the new struct.

// Function that calculates the desire number N to compute the elapsed days.

int	calculateN (struct date d)	// Here remember that you have defined a struct.
{					// So you need to declare a variable of that struct type.
	int	N;			// To operate in functions, assignements, etc.
	int	funcF (struct date d);
	int	funcG (struct date d);
		
	N = 1461 * funcF (d) / 4 + 153 * funcG (d) / 5 + d.day;

	if ( ( d.year == 1900 && d.month <= 2 ) || ( d.year <= 1899 && d.year > 1800 ) )
		N += 1;
	else if ( d.year == 1800 && d.month > 2 )
		N += 1;
	else if ( ( d.year == 1800 && d.month <= 2 ) || ( d.year <= 1799 && d.year > 1700 ) )
		N += 2;
	else if ( d.year == 1700 && d.month > 2 )
		N += 2;


	return N;
}

// Auxiliary function to the main function "calculateN".

int	funcF (struct date d)
{
	if ( d.month <= 2 )
		--d.year;

	return d.year;
}

// Auxiliary function to the main function "calculateN".

int	funcG (struct date d)
{
	if ( d.month <= 2 )
		d.month += 13;
	else
		++d.month;

	return d.month;
}

// Function to display the day of the week of a particular date.

void	displayDay (int N)
{
	int	result;

	result = ( N - 621049 ) % 7;

	switch ( result )
	{
		case 0:
			printf	("Sunday.\n");
			break;
		case 1:
			printf	("Monday.\n");
			break;
		case 2:
			printf	("Tuesday.\n");
			break;
		case 3:
			printf	("Wednesday.\n");
			break;
		case 4:
			printf	("Thursday.\n");
			break;
		case 5:
			printf	("Friday.\n");
			break;
		case 6:
			printf	("Saturday.\n");
			break;
		default:
			break;
	}
}

// MAIN FUNCTION.

int	main (void)
{
	struct	date firstDate;
	int	calculateN (struct date d);
	void	displayDay (int N);

	do {
		printf	("Please, enter the first date (mm/dd/yyyy): ");
		scanf	("%i/%i/%i", &firstDate.month, &firstDate.day, &firstDate.year);
		
		if ( firstDate.month < 1 || firstDate.month > 12 )
			printf	("\nSomething is wrong with the month, please, check again.\n");
		else if ( firstDate.day > 31 || firstDate.day < 1 )
			printf	("\nSomething is wrong with the day, please, check again.\n");
	}
	while ( firstDate.month < 1 || firstDate.month > 12 || firstDate.day > 31 || firstDate.day < 1 );
	
	printf	("The day %i/%i/%i fell on ", firstDate.month, firstDate.day, firstDate.year);

	displayDay (calculateN (firstDate));

	return 0;
}
