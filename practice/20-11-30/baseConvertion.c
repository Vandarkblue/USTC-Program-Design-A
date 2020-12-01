#include <stdio.h>
#include <math.h>

void baseConvert(int, int);

int main(void)
{
	int num;
	int command;

	scanf("%d", &num);
	scanf("%d", &command);

	baseConvert(num, command);

	return 0;
}

void baseConvert(int dec, int base)
{
	char digits[] = {"0123456789abcdefghijklmnopqrstuvwxyz"};
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
