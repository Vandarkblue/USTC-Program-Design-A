//exponentialGDP.c

//Given that the annual growth rate of GDP is 7%, seek the percentage 
//increase of GDP in 10 years compared to now.

#include <stdio.h>
#include <math.h>

int main(void)
{
	int n=10; //for n years
	double r=0.07, p; //annual gorwth rate et the final multiple

	p = pow(r+1, n);
	printf("%2.2lf%%\n", 100*(p-1)); //print the percentage
	//96.72%

	return 0;
}
