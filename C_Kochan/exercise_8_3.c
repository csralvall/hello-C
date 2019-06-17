// This is exercise 8.3 of the book "Programming in C" by Stephen G. Kochan.

// Program to calculate the elapsed time between two hours.

#include <stdio.h>

struct	time
{
	unsigned int	hours;
	unsigned int	minutes;
	unsigned int	seconds;
};

struct time	elapsed_time (struct time t1, struct time t2)
{
	struct time	result = { 0, 0, 0};

	if ( t1.hours <= t2.hours ) {
		result.seconds = t2.seconds + (60 - t1.seconds);
		while ( result.seconds >= 60 ) {
			result.seconds -= 60;
			++result.minutes;
		}
		result.minutes += t2.minutes + (60 - t1.minutes);
		while ( result.minutes >= 60 ) {
			result.minutes -= 60;
			++result.hours;
		}
		result.hours += t2.hours - (t1.hours + 1);
	} else if ( t1.hours > t2.hours ) {
		result.seconds = t2.seconds + (60 - t1.seconds);
		while ( result.seconds >= 60 ) {
			result.seconds -= 60;
			++result.minutes;
		}
		result.minutes += t2.minutes + (60 - t1.minutes);
		while ( result.minutes >= 60 ) {
			result.minutes -= 60;
			++result.hours;
		}
		result.hours += (24 - (t1.hours + 1) ) + t2.hours;
	}

	return result;
}

int	main (void)
{
	struct time	time1;
	struct time	time2;
	struct time	result;
	struct time	elapsed_time (struct time t1, struct time t2);

	printf	("\nPlease, type the first hour (hh:mm:ss): ");
	scanf	("%u:%u:%u", &time1.hours, &time1.minutes, &time1.seconds );

	printf	("\nPlease, type the second hour (hh:mm:ss): ");
	scanf	("%u:%u:%u", &time2.hours, &time2.minutes, &time2.seconds );

	result = elapsed_time (time1, time2);

	printf	("\nThe elapsed time between %.2u:%.2u:%.2u and %.2u:%.2u:%.2u was %.2u:%.2u:%.2u.\n",
			time1.hours, time1.minutes, time1.seconds, time2.hours, time2.minutes,
			time2.seconds, result.hours, result.minutes, result.seconds);

	return 0;
}
