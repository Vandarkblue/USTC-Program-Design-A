/* intToDIgits.c -- Tan Haoqiang Page 216 Task 8 */

#include <stdio.h>

void intToCharRecursion(int);

int main(void)
{
	int a;
	scanf("%d", &a);

	intToCharRecursion(a);

	return 0;
}

void intToCharRecursion(int a)
{
	if (a > 9)
	{
		intToCharRecursion(a/10);
	}
	printf("%d ", a%10);
}
