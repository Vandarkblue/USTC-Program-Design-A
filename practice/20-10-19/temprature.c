/* temprature.c -- Task 5 */
/* Fahrenheit to Celcius Converter */

#include <stdio.h>

int main(void)
{
	double c, f;

	scanf("%lf", &f);

	c = 5*(f-32.0)/9.0;

	printf("%lf", c);
	
	return 0;
}
