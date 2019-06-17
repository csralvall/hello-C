#include <stdlib.h>
#include "array_helpers.h"

int minHist(WeatherTable array) {

	int minHist = (array[0][0][0])._min_temp;
	
	for ( unsigned int y = 0u; y < 37 ; ++y )
		for ( unsigned int m = 0u; m < 12 ; ++m )
			for ( unsigned int d = 0u; d < 28 ; ++d )
			    if ( minHist > array[y][m][d]._min_temp )
				minHist = array[y][m][d]._min_temp;
	return minHist;
}

void maxYear(WeatherTable array, int output1[37]) {
	
	int maxYear = 0;
	
	for ( unsigned int y = 0u; y < 37 ; ++y ) {
		maxYear = (array[y][0][0])._max_temp;
		for ( unsigned int m = 0u; m < 12 ; ++m )
			for ( unsigned int d = 0u; d < 28 ; ++d )
			    if ( maxYear < array[y][m][d]._max_temp ){
				maxYear = array[y][m][d]._max_temp;
			    }
		output1[y] = maxYear;
	}
}

void monthRain(WeatherTable array, t_month output2[37]) {

	unsigned int maxRain = 0u;
	t_month monthRMax = january;

	for ( unsigned int y = 0u; y < 37 ; ++y ) {
		maxRain = (array[0][0][0])._rainfall;
		monthRMax = january;
		for ( unsigned int m = 0u; m < 12 ; ++m )
			for ( unsigned int d = 0u; d < 28 ; ++d )
			    if ( maxRain < array[y][m][d]._rainfall ){
				maxRain = array[y][m][d]._rainfall;
				monthRMax = january;
			    }
		output2[y] = monthRMax; // Save in each month the max rainfall.
	}
}
