#include <stdio.h>
#include <math.h>
#include <stdbool.h>

const char digits[] = {"0123456789abcdefghijklmnopqrstuvwxyz"};

int baseInput(int, char []);
bool legality(int, char []);
int valueDigit(char);
void baseConvert(int, int);

int main(void)
{
	int baseI, baseO, num;
	char input[0xff] = "USTC Program Design by Dec_Randomizer";
	
	while (*input != '\0')
	{
		printf("Input base: ");
		scanf("%d", &baseI);
		printf("Input number: ");
		scanf("%s", input);
		if (!legality(baseI, input))
		{
			printf("Error input.\n");
			continue;
		}
		printf("Output base: ");
		scanf("%d", &baseO);
		num = baseInput(baseI, input);
		baseConvert(num, baseO);
		return 0;
	}
	
}

int baseInput(int base, char input[])
{
	int sum = 0;
	int value;
	for (int i = 0; input[i] != '\0'; i++)
	{
		value = valueDigit(input[i]);
		sum = sum * base + value;
	}
	return sum;
}

bool legality(int base, char input[])
{
	int value;
	for (int i = 0; input[i] != 0; i++)
	{
		value = valueDigit(input[i]);
		if (value >= base || value == -1)
		{
			return false;
		}
		
	}
	return true;
}

int valueDigit(char a)
{
	for (int i = 0; i < 36; i++)
	{
		if (digits[i] == a)
		{
			return i;
		}
		
	}
	return -1;
}

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
