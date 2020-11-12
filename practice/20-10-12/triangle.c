/* triangle.c -- Task 3 */

#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b, c, s, area; // s as semiperimeter

	printf("input a:");
	scanf("%lf", &a);
	printf("input b:");
	scanf("%lf", &b);
	printf("input c:");
	scanf("%lf", &c);

	if(a+b>c && a+c>b && c+b>a)
	{
		s = (a+b+c) / 2.0;
		area = sqrt(s * (s-a) * (s-b) * (s-c)); // Heron's fomula

		printf("a = %6.2f, b = %6.2f, c = %6.2f\n", a, b, c);
		printf("s = %-8.2f, area = %-8.2f\n", s, area);

	}
	else
	{
		printf("Cannot form a triangle.");
	}

	return 0;
}
