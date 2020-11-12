/* isPrime.c -- Tan Haoqiang Page 166 Task 9 modified */
/* ------------------------------------ */
/*   Licensed under the MIT License     */
/*  Copyright (c) 2020 Dec.Randomizer   */
/* ------------------------------------ */
/* Use two ways to find a number in a sequenced array. */

#include <stdio.h>

#define N 15

/* Search for integer obj in array_a, and s is the length of a. */
int searchBinary(int a[], int s, int obj);
int searchSequence(int a[], int s, int obj);

int main(void)
{
	int a[N];
	int obj, r;

	for (size_t i = 0; i < N; i++)
	{
		a[i] = 2*i +1;
	}

	printf("Input the integer to find:\n");
	scanf("%d", &obj);

	printf("%d is located as a[%d].\n", obj, searchSequence(a, N, obj));
	printf("Yes, it is a[%d].\n", searchBinary(a, N, obj));

	return 0;
}

int searchBinary(int a[], int s, int obj) /* Faster */
{
	int boundUpper, boundLower, median;

	boundLower = 0;
	boundUpper = s - 1;

	while (boundLower <= boundUpper)
	{
		median = (boundLower + boundUpper)/2;

		if (a[median] > obj)
		{
			boundUpper = median - 1;
		}
		else if (a[median] < obj)
		{
			boundLower = median + 1;
		}
		else
		{
			return median;
		}

	} // while

	return -1;
}

int searchSequence(int a[], int s, int obj)
{
	for (size_t i = 0; i < s; i++)
	{
		if (obj == a[i])
		{
			return i;
		}
	}
	return -1;
}
