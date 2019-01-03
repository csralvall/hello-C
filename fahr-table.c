#include <stdio.h>

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300; flating-point version */

int main ()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;	/* lower limit of tmperature table */
	upper = 300;	/*upper limit */
	step = 20;	/* step size */

	fahr = lower;
	printf("\tFahrenheit-Celsius table\n");	
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("\t\t%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
