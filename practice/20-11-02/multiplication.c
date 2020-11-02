#include <stdio.h>

int main(void)
{
	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < i + 1; j++)
		{
			printf("%d*%d=%d", i+1, j+1, (i+1)*(j+1));
			putchar(' ');
		}
		putchar('\n');
	}
	
	return 0;
}
