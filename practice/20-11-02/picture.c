#include <stdio.h>

int main(void)
{
	for (size_t i = 0; i < 6; i++)
	{
		for (size_t j = 0; j < 7-i; j++)
		{
			putchar(' ');
		}
		for (size_t j = 0; j < 2*i + 1; j++)
		{
			putchar('*');
		}
		putchar('\n');

	} // for i

	return 0;
}
