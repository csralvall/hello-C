#include <stdio.h>

#define LOWER	0	/* lower limit of temperature table */
#define UPPER	300	/*upper limit */
#define STEP	20	/* step size */

float converter(float f);

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300; floating-point version */

int main()
{
	float fahr = LOWER;

	printf("\tFahrenheit-Celsius table\n");	
	while (fahr <= UPPER) {
		printf("\t\t%3.0f %6.1f\n", fahr, converter(fahr));
		fahr = fahr + STEP;
	}
}

float converter(float fahr)
{
	float celsius;

	celsius = (5.0/9.0) * (fahr-32.0);

	return celsius;
}
