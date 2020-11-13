/* equationQuadratic.c -- Tan Haoqiang Page 215 Task 2 */
/* ------------------------------------ */
/*   Licensed under the MIT License     */
/*  Copyright (c) 2020 Dec.Randomizer   */
/* ------------------------------------ */
/* Confusing task. Why do we need 3 functions? */

#include <stdio.h>
#include <math.h>

void printRootEquationQuadRealSingle(double);
void printRootEquationQuadRealDualReal(double, double);
void printRootEquationQuadRealDualComplex(double, double);

int main(void)
{
	double a, b, c, d, f;

	printf("Input a:");
	scanf("%lf", &a);
	printf("Input b:");
	scanf("%lf", &b);
	printf("Input c:");
	scanf("%lf", &c);

	d = (b*b - 4*a*c) / (2*a);
	f = -b / (2*a);

	if (a == 0)
	{
		printRootEquationQuadRealSingle(-c/b);
	}
	else if (d == 0)
	{
		printRootEquationQuadRealSingle(f);
	}
	else if (d > 0)
	{
		printRootEquationQuadRealDualReal(d, f);
	}
	else
	{
		printRootEquationQuadRealDualComplex(d, f);
	}
	return 0;
}

void printRootEquationQuadRealSingle(double f)
{
	printf("This equation has 1 real root.\n");
	printf("x = %lf\n", f);
}

void printRootEquationQuadRealDualReal(double d, double f)
{
	d = sqrt(d);

	printf("This equation has 2 real roots.\n");
	printf("x_1 = %lf\nx_2 = %lf\n", f+d, f-d);
}

void printRootEquationQuadRealDualComplex(double d, double f)
{
	d = sqrt(-d);
	printf("This equation has 2 complex roots.\n");
	printf("x_1 = %lf+%lfi\nx_2 = %lf-%lfi\n", f, d, f, d);
}
