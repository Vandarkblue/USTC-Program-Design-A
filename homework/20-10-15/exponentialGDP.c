/* exponentialGDP.c -- Tan Haoqiang page 80 task 1 */

/* Given that the annual growth rate of GDP is 7%,
/* seek the percentage increase of GDP in 10 years compared to now. */

#include <stdio.h>
#include <math.h>

int main(void)
{
	int n=10; // for n years
	double r=0.07; // annual gorwth rate
	double p; // The final multiple

	p = pow(r+1, n);
	
	printf("%2.2lf%%\n", 100*(p-1)); // print the percentage

	// Output 96.72%

	return 0; // Good habit
}
