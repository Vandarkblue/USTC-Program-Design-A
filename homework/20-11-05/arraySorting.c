/* arraySorting.c -- Tan Haoqiang pgae 165 task 4 modified */
/* Sort a int array then insert another integer */
/* Kind of RAM-wasting, for 2 nearly equivalent arraies here */

#include <stdio.h>

int main(void)
{
	int n, a, k;

	printf("The scale of the array is: ");
	scanf("%d", &n);

	int p[n], q[n+1];

	for (size_t i = 0; i < n; i++)
	{
		printf("The Integer %d is: ", i+1);
		scanf("%d", &p[i]);
	}

	/* Bubble sort O(n^2) */
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n - i + 1; j++)
		{
			if (p[j] > p[j+1])
			{
				p[j] ^= p[j+1];
				p[j+1] ^= p[j];
				p[j] ^= p[j+1];
			}
		}
	}

	printf("The sorted array is: ");

	for (size_t i = 0; i < n; i++)
	{
		printf("%d, ", p[i]);
	}
	putchar('\n');

	/* Insert a integer */
	printf("The new integer is: ");
	scanf("%d", &a);

	/* Find the location where the integer should lie */
	for (size_t i = 0; i < n; i++) 
	{
		if (p[i] >= a)
		{
			k = i;
			break;
		}
	}
	for (size_t i = 0; i < k; i++)
	{
		q[i] = p[i];
	}

	q[k] = a;

	for (size_t i = k; i < n; i++)
	{
		q[i+1] = p[i];
	}

	printf("The array with the new integer is: ");
	for (size_t i = 0; i < n+1; i++)
	{
		printf("%d, ", q[i]);
	}
	putchar('\n');

	return 0;
}
