/* arraySortDual.c -- Task 2 */

#include <stdio.h>

int main(void)
{
	int a[10] = {0}, b[5] = {0};
	int temp;

	for (size_t i = 0; i < 5; i++)
	{
		printf("The Integer %d of array A is: ", i+1);
		scanf("%d", &a[i]);
	}

	for (size_t i = 0; i < 5; i++)
	{
		printf("The Integer %d of array B is: ", i+1);
		scanf("%d", &b[i]);
		a[i+5] = b[i];
	}

	/* Bubble sort O(n^2) */
	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 9 - i; j++)
		{
			if (a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

	for (size_t i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');

	for (size_t i = 0; i < 5; i++)
	{
		printf("%d ", b[i]);
	}
	putchar('\n');

	return 0;		
}
