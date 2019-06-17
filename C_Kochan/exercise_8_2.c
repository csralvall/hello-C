// This is exercise 8.2 of the book "Programming in C" by Stephen G. Kochan.

// Program to calculate the number of days elapsed between to dates.

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

// MAIN FUNCTION.

int	main (void)
{
	struct	date firstDate;
	struct	date secondDate;
	int	elapsedDays;
	int	calculateN (struct date d);

	// You have to consider the dates before 1900.

	do {
		printf	("Please, enter the first date (mm/dd/yyyy): ");
		scanf	("%i/%i/%i", &firstDate.month, &firstDate.day, &firstDate.year);
		
		if ( firstDate.month < 1 || firstDate.month > 12 )
			printf	("\nSomething is wrong with the month, please, check again.\n");
		else if ( firstDate.day > 31 || firstDate.day < 1 )
			printf	("\nSomething is wrong with the day, please, check again.\n");
	}
	while ( firstDate.month < 1 || firstDate.month > 12 || firstDate.day > 31 || firstDate.day < 1 );
	
	do {
		printf	("Please, enter the second date (mm/dd/yyyy): ");
		scanf	("%i/%i/%i", &secondDate.month, &secondDate.day, &secondDate.year);
		
		if ( secondDate.month < 1 || secondDate.month > 12 )
			printf	("\nSomething is wrong with the month, please, check again.\n");
		else if ( secondDate.day > 31 || secondDate.day < 1 )
			printf	("\nSomething is wrong with the day, please, check again.\n");
	}
	while ( secondDate.month < 1 || secondDate.month > 12 || secondDate.day > 31 || secondDate.day < 1 );

	elapsedDays = calculateN (firstDate) - calculateN (secondDate);

	printf	("The elapsed days between %i/%i/%i and %i/%i/%i is %i.\n",
			firstDate.month, firstDate.day, firstDate.year,
			secondDate.month, secondDate.day, secondDate.year,
			elapsedDays);

	return 0;
}
