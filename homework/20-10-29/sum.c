/* sum.c -- Tan Haoqiang page 137 task 5 */
/* ------------------------------------ */
/*   Licensed under the MIT License     */
/*  Copyright (c) 2020 Dec.Randomizer   */
/* ------------------------------------ */

#include <stdio.h>

int main(void)
{
	int a, n;
	long long s;

	printf("a = ");
	scanf("%d",&a);
	printf("n = ");
	scanf("%d",&n);

	long long c[n]; // Variable-length array

	c[0] = a;
	s = c[0];

	for (size_t i = 1; i < n; i++)
	{
		c[i] = 10 * c[i-1] + a;
		s += c[i];
	}

	printf("The sum is %lld.\n",s);
	
	return 0;
}
