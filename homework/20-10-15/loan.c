/* loan.c -- Tan Haoqiang page 80 task 3 */

#include <stdio.h>
#include <math.h>

int main(void)
{
	double d, p, r, m;

	d = 300000;
	p = 6000;
	r = 0.01;

	m = log(p/(p-d*r))/log(1+r);
	
	printf("%2.1lf\n", m); // MinGW automatically rounding
	
	// Output 69.7

	return 0; // Good habit
}
