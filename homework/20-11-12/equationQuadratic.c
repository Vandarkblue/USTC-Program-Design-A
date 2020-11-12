/* equationQuadratic.c -- Tan Haoqiang Page 215 Task 2 */
/* ------------------------------------ */
/*   Licensed under the MIT License     */
/*  Copyright (c) 2020 Dec.Randomizer   */
/* ------------------------------------ */
/* Confusing task. Why do we need 3 functions? */

#include <stdio.h>
#include <math.h>
#include <complex.h>

int delta_0(void);
int delta_1(int, int, int);
_Complex delta_2(int, int, int);

int main(void)
{
	int a, b, c;
	_Complex d;

	printf("Input a:");
	scanf("%d", &a);
	printf("Input b:");
	scanf("%d", &b);
	printf("Input c:");
	scanf("%d", &c);

	d = b*b-4*a*c;

	if (creal(d) > 0)
	{
		d = delta_0();
	}
	else if (creal(d) == 0)
	{
		d = delta_1(a, b, c);
	}
	else
	{
		d = delta_2(a, b, c);
	}
	
	printf("The two roots are %f +%fi and %f %fi\n", (-b+creal(d))/(2*a), cimag(d)/(2*a), (-b-creal(d))/(2*a), -cimag(d)/(2*a));
	
}

int delta_0(void)
{
	return 0;
}

int delta_1(int a, int b, int c)
{
	return sqrt(b*b-4*a*c);
}

_Complex delta_2(int a, int b, int c)
{
	return csqrt(b*b-4*a*c);
}
