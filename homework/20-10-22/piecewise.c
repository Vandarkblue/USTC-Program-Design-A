/* piecewise.c -- Tan Haoqiang page 108 task 6 */

#include <stdio.h>

int main(void)
{
	/* Predefine */
	double x, y;

	/* Input */
	printf("x = ");
	scanf("%lf",&x);

	/* Calculating */
	if ( x < 1.0 )
	{
		y = x;
	}
	else if ( x < 10.0 )
	{
		y = 2.0*x - 1.0;
	}
	else
	{
		y = 3.0*x - 11.0;
	}

	/* Output */
	printf("y = %lf",y);

	return 0;
}
