/* reverse.c -- Tan Haoqiang page 109 task 9 modified */
/* This program can process more than 5 digits. */

#include <stdio.h>

int main(void)
{
	int num, t;

	int n = 0, i = 0;

	printf("a = ");
	scanf("%d", &num);
	t = num;

	while (t > 0)
	{
		t /= 10;
		n++;
	}
	printf("The length is %d.\n", n);

	int c[n]; // Variable-length array

	for (int i = 0; i < n; i++)
	{
		c[i] = num % 10;
		num /= 10;
	}

	/* Ascending */
	for (int i = n-1; i >= 0; i--)
	{
		printf("%d, ", c[i]);
	}
	putchar('\n');

	/* Descending */
	for (int i = 0; i < n; i++)
	{
		printf("%d, ", c[i]);
	}
	putchar('\n');

	return 0;
}
