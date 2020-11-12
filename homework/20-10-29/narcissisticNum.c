/* narcissisticNum.c -- Tan Haoqiang page 137 task 8 */

#include <stdio.h>

int main(void)
{
	int c, d, u;

	for (size_t i = 100; i < 1000; i++)
	{
		c = i / 100;
		d = i / 10 % 10;
		u = i % 10;
		if (c*c*c + d*d*d + u*u*u == i)
		{
			printf("%d ", i);
		}
		
	}

	return 0;
}
