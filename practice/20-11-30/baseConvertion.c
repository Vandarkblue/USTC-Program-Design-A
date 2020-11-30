#include <stdio.h>

void baseConvertDecBin(int);
void baseConvertDecOct(int);
void baseConvertDecHex(int);

int main(void)
{
	int num;
	int command;
	scanf("%d", &num);
	scanf("%d", &command);
	switch (command)
	{
	case 2:
		baseConvertDecBin(num);
		break;
	case 8:
		baseConvertDecOct(num);
		break;
	case 16:
		baseConvertDecHex(num);
		break;
	default:
		break;
	}
	return 0;
}

void baseConvertDecBin(int dec)
{
	char digits[] = {"01"};
	if (dec < 0)
	{
		putchar('-');
		baseConvertDecBin(-dec);
	}
	else if (dec == 0)
	{
		return;
	}
	else
	{
		baseConvertDecBin(dec/2);
		printf("%c", digits[dec%2]);
	}
	return;
}

void baseConvertDecOct(int dec)
{
	char digits[] = {"01234567"};
	if (dec < 0)
	{
		putchar('-');
		baseConvertDecOct(-dec);
	}
	else if (dec == 0)
	{
		return;
	}
	else
	{
		baseConvertDecOct(dec/8);
		printf("%c", digits[dec%8]);
	}
	return;
}

void baseConvertDecHex(int dec)
{
	char digits[] = {"0123456789abcdef"};
	if (dec < 0)
	{
		putchar('-');
		baseConvertDecHex(-dec);
	}
	else if (dec == 0)
	{
		return;
	}
	else
	{
		baseConvertDecHex(dec/16);
		printf("%c", digits[dec%16]);
	}
	return;
}
