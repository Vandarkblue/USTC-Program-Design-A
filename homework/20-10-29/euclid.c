/* euclid.c -- Tan Haoqiang page 137 task 3 */

#include <stdio.h>

unsigned maxCommonFactor(unsigned, unsigned);

int main(void)
{
	unsigned m, n, t;

	printf("Please input the two integers.\nm = ");
	scanf("%u", &m);
	printf("n = ");
	scanf("%u", &n);

	t = maxCommonFactor(m, n);

	printf("The maximal common factor of %u and %u is %u.\n", m, n, t);
	printf("The minimal common multiple of %u and %u is %u.\n", m, n, m * n / t);

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
