/* tax.c -- Task 3 */

#include <stdio.h>

int main(void)
{
	double a, b;

	printf("Input the amount:");
	scanf("%lf",&a);
	printf("Tax: ");

	if (a<=3000.0) b = 0;
	else if (a<=3500.0) b = 0.05*a;
	else if (a<=5000.0) b = 0.20*a;
	else b = 0.25*a;

	printf("%lf",b);

	return 0;
}
