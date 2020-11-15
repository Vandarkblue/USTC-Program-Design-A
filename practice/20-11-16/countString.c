/* countString.c -- Task 3 */
/* ------------------------------------ */
/*   Licensed under the MIT License     */
/*  Copyright (c) 2020 Dec.Randomizer   */
/* ------------------------------------ */
/* We assum that the input text has been formatted. */

#include <stdio.h>

#define LENGTH 50

int countWord(char*);
int countSpace(char*);

int main(void)
{
	char str[LENGTH];
	gets(str);

	printf("%d, %d", countSpace(str), countWord(str));

	return 0;
}

int countWord(char str[])
{
	int n = 0, j = 0;
	while (str[n] != '\0')
	{
		++n;
	}
	for (size_t i = 1; i < n; i++)
	{
		if (str[i] != ' ' && str[i-1] == ' ')
		{
			++j;
		}
	}
	return j+1;
}

int countSpace(char str[])
{
	int i = 0, j = 0;
	while (str[i] != '\0')
		{
			if (str[i] == ' ')
			{
				++j;
			}
			++i;
		}
	return j;
}
