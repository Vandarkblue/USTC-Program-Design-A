// Tan Haoqiang page 108 task 6

#include <stdio.h>

int main(void)
{
	// Predefine
	double piecewise();
	double x;

	// IO
	printf("x = ");
	scanf("%lf",&x);
	printf("y = %lf",piecewise(x));

	return 0; // Good habit
}

double piecewise(double x)
{
	if ( x < 1.0 ) return x;
	else if ( x < 10.0 ) return 2.0*x - 1.0;
	else return 3.0*x - 11.0;
}
