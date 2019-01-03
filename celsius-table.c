#include <stdio.h>

/* print Celsius-Fahrenheit table for fahr = 0, 20, ..., 300; flating-point version */

int main ()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;	/* lower limit of tmperature table */
	upper = 300;	/*upper limit */
	step = 20;	/* step size */

	fahr = lower;
	printf("\tCelsius-Fahrenheit table\n");	
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("\t\t%6.1f %3.0f\n", celsius, fahr);
		fahr = fahr + step;
	}
}
