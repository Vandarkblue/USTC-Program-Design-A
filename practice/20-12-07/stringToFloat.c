#include <stdio.h>
#include <math.h>

#define N 0xff

// -1.03e+09

float strToFloatT(char*);

int main(void)
{
	char a[] = "-1.03e+09";
	char *p = a;
	int i = 0;
	
	// printf("%s\n", a);

	printf("%f", strToFloatT(p));

	return 0;
}

float strToFloatT(char *s)
{
	float object;

	_Bool isNegative = 0;
	float fInteger = 0.0f;

	_Bool hasDec = 0;
	float fDecimal = 0.0f;
	float fDecPower = 0.1f;

	_Bool meetE = 0;
	_Bool negativeExponent = 0;
	int exponent = 0;

	if (!s)
	{
		return 0.0f;
	}
	else if (*s == '-')
	{
		isNegative = 1;
	}
	else if (*s == '+')
	{
		isNegative = 0;
	}
	if (*s >= '0' && *s <= '9')
	{
		--s;
	}
	while (*s != '\0')
	{
		++s;
		if (meetE)
		{
			if (*s >= '0' && *s <= '9') 
			{
				exponent = exponent*10 + *s - '0';
			}
			if (*s == '-')
			{
				negativeExponent = 1;
			}
		}
		else if (hasDec)
		{
			if (*s >= '0' && *s <= '9')
			{
				fDecimal = fDecimal + (*s -'0') * fDecPower;
				fDecPower = fDecPower / 10.0;
				continue;
			}
			else
			{
				if (*s == 'e')
				{
					meetE = 1;
					continue;
				}
			}
			
		}
		else if (*s >= '0' && *s <= '9')
		{
			fInteger = fInteger*10 + *s - '0';
			continue;
		}
		else if (*s == 'e')
		{
			meetE = 1;
			hasDec = 0;
			continue;
		}
		else if (*s == '.')
		{
			hasDec = 1;
			continue;
		}
		
	} // while not '\0'

	if (negativeExponent)
	{
		exponent = -exponent;
	}
	
	object = (fInteger + fDecimal) * pow(10, exponent);

	if (isNegative)
	{
		object = -object;
	}

	// printf("%f, %f, %d\n", fInteger, fDecimal, exponent);

	return object;
}
