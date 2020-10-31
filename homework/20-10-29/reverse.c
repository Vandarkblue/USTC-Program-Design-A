/* reverse.c -- Tan Haoqiang page 109 task 9 modified */
/* This program can process more than 5 digits. */
/* ------------------------------------ */
/*   Licensed under the MIT License     */
/*  Copyright (c) 2020 Dec.Randomizer   */
/* ------------------------------------ */

#include <stdio.h>

int main(void)
{
	size_t a;

	size_t n = 0, i = 0;

	printf("a = ");
	scanf("%lld", &a);

	for (size_t t = a; t >= 1; t /= 10)
	{
		n++;
	}
	printf("The length is %lld.\n", n);

	size_t c[n-1]; // Variable-length array
	
	for (size_t t = a; i < n; t /= 10)
	{
		c[i] = t%10;
		i++;
	}

	/* Ascending */
	for (size_t i = 0; i < n; i++)
	{
		printf("%d, ", c[n-i-1]);
	}
	putchar('\n');

	/* Descending */
	for (size_t i = 0; i < n; i++)
	{
		printf("%d, ", c[i]);
	}
	putchar('\n');

	return 0;
}
