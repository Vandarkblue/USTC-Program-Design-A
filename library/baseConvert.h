#include <stdio.h>

const char digits[] = {"0123456789abcdefghijklmnopqrstuvwxyz"};

void baseConvert(int dec, int base)
{
	if (base > 36)
	{
		return;
	}
	if (dec < 0)
	{
		putchar('-');
		baseConvert(-dec, base);
	}
	else if (dec == 0)
	{
		return;
	}
	else if (dec < base)
	{
		printf("%c", digits[dec % base]);
	}
	else
	{
		baseConvert(dec / base, base);
		printf("%c", digits[dec % base]);
	}
	return;
}
