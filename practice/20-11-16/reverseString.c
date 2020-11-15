/* reverseString.c -- Task 2 */
/* ------------------------------------ */
/*   Licensed under the MIT License     */
/*  Copyright (c) 2020 Dec.Randomizer   */
/* ------------------------------------ */

#include <stdio.h>

char *reverseString(char*);

int main(void)
{
	char a[0xff];
	printf("Input string:");
	gets(a);

	reverseString(a);

	printf("Inverted string:");
	puts(a);

	return 0;
}

char *reverseString(char a[])
{
	int n = 0;

	while (a[n] != '\0')
	{
		++n;
	}

	char b[n];

	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		a[i] = b[n-i-1];
	}

	return a;
}
