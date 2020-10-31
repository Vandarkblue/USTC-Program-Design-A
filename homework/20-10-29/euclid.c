/* euclid.c -- Tan Haoqiang page 137 task 3 */
/* ------------------------------------ */
/*   Licensed under the MIT License     */
/*  Copyright (c) 2020 Dec.Randomizer   */
/* ------------------------------------ */

#include <stdio.h>

unsigned maxCommonFactor(unsigned a, unsigned b);

int main(void)
{
	unsigned m, n, t;

	printf("Please input the two integers.\nm = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);

	t = maxCommonFactor(m, n);
	printf("The maximal common factor of %d and %d is %d.\n", m, n, t);
	printf("The minimal common multiple of %d and %d is %d.\n", m, n, m * n / t);

	return 0;
}

unsigned maxCommonFactor(unsigned a, unsigned b) /* Recursion */
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return maxCommonFactor(b, a % b);
	}
}
