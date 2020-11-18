/* equationQuadratic.c -- Tan Haoqiang Page 215 Task 2 modified */
/* Confusing task. Why do we need 3 functions?
* Here only one with 3 arguments.
*/

#include <stdio.h>
#include <math.h>

extern int scanf();

void printRootEqationQuad(double, double, double);

int main(void)
{
	/* a*x^2 + b*x + c == 0 */
	double a, b, c;

	printf("Input a:");
	scanf("%lf", &a);
	printf("Input b:");
	scanf("%lf", &b);
	printf("Input c:");
	scanf("%lf", &c);

	printRootEqationQuad(a, b, c);

	return 0;
}

void printRootEqationQuad(double a, double b, double c)
{
	double d = b*b - 4*a*c;

	if (a == 0)
	{
		printf("This equation has 1 real root.\n");
		printf("x = %lf\n", -c/b);
	}
	else if (d == 0)
	{
		printf("This equation has 1 real root.\n");
		printf("x = %lf\n", -b/(2*a));
	}
	else if (d > 0)
	{
		printf("This equation has 2 real roots.\n");
		printf("x_1 = %lf\nx_2 = %lf\n", (-b+sqrt(d))/(2*a), (-b-sqrt(d))/(2*a));
	}
	else
	{
		/* In-line declairation acceptable in C99
		* avoiding unused variable in other case.
		*/
		double f = sqrt(-d)/(2*a);
		printf("This equation has 2 complex roots.\n");
		printf("x_1 = %lf+%lfi\nx_2 = %lf-%lfi\n", -b/(2*a), f, -b/(2*a), f);
	}
}
