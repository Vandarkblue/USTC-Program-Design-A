/* euclidFunction.c -- Task 1 */
/* ------------------------------------ */
/*   Licensed under the MIT License     */
/*  Copyright (c) 2020 Dec.Randomizer   */
/* ------------------------------------ */
/* Ref homework\20-11-29\euclid.c */

#include <stdio.h>

unsigned factorCommonMax(unsigned, unsigned);
unsigned multipleCommonMinFast(unsigned, unsigned, unsigned);

int main(void)
{
	unsigned m, n, t;

	printf("Please input the two integers.\nm = ");
	scanf("%u", &m);
	printf("n = ");
	scanf("%u", &n);

	t = factorCommonMax(m, n);

	printf("The maximal common factor of %u and %u is %u.\n", m, n, t);
	printf("The minimal common multiple of %u and %u is %u.\n", m, n, multipleCommonMinFast(m, n, t));

	return 0;
}

unsigned factorCommonMax(unsigned a, unsigned b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return factorCommonMax(b, a % b);
	}
}

unsigned multipleCommonMinFast(unsigned a, unsigned b, unsigned f)
{
	return a * b / f;
}
