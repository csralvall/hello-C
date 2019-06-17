// This is exercise 8.3 of the book "Programming in C" by Stephen G. Kochan.

// Program to update the hour and the date.

#include <stdio.h>
#include <stdbool.h>

// This structure saves the time.

struct	time
{
	unsigned int	hour;
	unsigned int	minute;
	unsigned int	second;
};


// This structure saves the date.

struct	date
{
	unsigned int	month;
	unsigned int	day;
	unsigned int	year;
};

// This structure saves the date and the time.

struct	dateAndTime
{
	struct time	stime;
	struct date	sdate;
};

// Function to update the time.

struct time	timeUpdate (struct time now)
{
	++now.second;

	if ( now.second == 60 ) {		// Next minute.
		now.second = 0;
		++now.minute;

		if ( now.minute == 60 ) {	// Next hour.
			now.minute = 0;
			++now.hour;

			if ( now.hour == 24 )	// Midnight.
				now.hour = 0;
		}
	}

	return now;
}

// Function to update the date.

struct date	dateUpdate (struct date today)
{
	struct date	tomorrow;
	unsigned int	numberOfDays (struct date d);

	if ( today.day != numberOfDays (today) ) {
		tomorrow.day = today.day + 1;
		tomorrow.month = today.month;
		tomorrow.year = today.year;
	}
	else if ( today.month == 12 ) {		// End of year.
		tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = today.year + 1;
	}
	else {					// End of month.
		tomorrow.day = 1;
		tomorrow.month = today.month + 1;
		tomorrow.year = today.year;
	}

	return tomorrow;
}

// Function to find the number of days in a month.

unsigned int	numberOfDays (struct date d)
{
	unsigned int	days;
	bool		isLeapYear (struct date d);
	const int	daysPerMonth[12] =
		{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if ( isLeapYear (d) && d.month == 2 )
		days = 29;
	else
		days = daysPerMonth[d.month - 1];

	return days;
}

// Function to determine if it's a leap year.

bool	isLeapYear (struct date d)
{
	bool	leapYearFlag;

	if ( (d.year % 4 == 0 && d.year % 100 != 0 ) || d.year % 400 == 0 )
		leapYearFlag = true;						// It's a leap year. 
	else
		leapYearFlag = false;						// Not a leap year.

	return leapYearFlag;
}

// Function to update the date and time.

struct dateAndTime	clockKeeper (struct dateAndTime dt)
{
	unsigned int	lastHour = dt.stime.hour;	
	struct time	timeUpdate (struct time now);
	struct date	dateUpdate (struct date today);

	dt.stime = timeUpdate (dt.stime);

	if ( lastHour == 23 && dt.stime.hour == 0 )
		dt.sdate = dateUpdate (dt.sdate);

	return dt;
}

// Main function.

int	main (void)
{
	struct dateAndTime	thisDay;
	struct dateAndTime	nextMoment;
	struct dateAndTime	clockKeeper (struct dateAndTime dt);

	printf	("Please, insert the time (hh:mm:ss) and the date (mm/dd/yyyy): \n");
	printf	("Time: \n");
	scanf	("%u:%u:%u", &thisDay.stime.hour, &thisDay.stime.minute, &thisDay.stime.second);

	printf	("Date: \n");
	scanf	("%u/%u/%u", &thisDay.sdate.month, &thisDay.sdate.day, &thisDay.sdate.year);

	nextMoment = clockKeeper (thisDay);

	printf	("Next moment: %.2u:%.2u:%.2u, %.2u/%.2u/%.2u\n", nextMoment.stime.hour, nextMoment.stime.minute,
			nextMoment.stime.second, nextMoment.sdate.month, nextMoment.sdate.day, nextMoment.sdate.year );

	return 0;
}
