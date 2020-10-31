/* sorting.c -- Tan Haoqiang page 107 task 4 modified */

#include <stdio.h>

/* Generally NUM <= 26, otherwise it requires rewriting */
#define NUM 3

int main(void)
{
	/* Predefine */
	int s[NUM]; // Value
	char t[NUM]; // Character

	for (size_t i = 0; i < NUM; i++)
	{
		t[i] = i + 'a'; // If NUM > 26, rewrite this
	}

	/* Input */
	for (size_t i = 0; i < NUM; i++)
	{
		printf("%c = ", t[i]);
		scanf("%d", &s[i]);
	}

	/* Selection Sorting O(n^2) */
	for (size_t i = 0; i < NUM - 1; i++)
	{
		int min = i;
		for (size_t j = i + 1; j < NUM; j++)
		{
			if (s[min] < s[j])
			{
				min = j;
			}
			if (min != i)
			{
				s[i] ^= s[min];
				s[min] ^= s[i];
				s[i] ^= s[min];

				t[i] ^= t[min];
				t[min] ^= t[i];
				t[i] ^= t[min];
			}
		}
	}

	/* Output */
	for (size_t i = 0; i < NUM; i++)
	{
		printf("%c = %d, ", t[i], s[i]);
	}
	printf("\n");

	return 0;
}
