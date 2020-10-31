/* maximum.c -- Task 2 */

#include <stdio.h>

int main(void)
{
	int a, b, c, max;

	printf("Enter a:");
	scanf("%d", &a);
	printf("Enter b:");
	scanf("%d", &b);
	printf("Enter c:");
	scanf("%d", &c);

	max = a;
	if (max < b)
	{
		max = b;
	}
	if (max < c)
	{
		max = c;
	}

	printf("max=%d\n", max);

	return 0;
}
