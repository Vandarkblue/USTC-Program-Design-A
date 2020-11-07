/* stract.c -- Tan Haoqiang pgae 166 task 13 */

#include <stdio.h>

#define LENGTH 32767

int main(void)
{
	char a[LENGTH], b[LENGTH];
	size_t i, j, k;

	printf("Input String A: ");
	gets(a);
	printf("Input String B: ");
	gets(b);

	i = 0;

	do
	{
		++ i;
	} while (a[i] != '\0');

	for (j = 0; b[j] != '\0'; ++j)
	{
		a[i+j] = b[j];
	}
	for (k = 0; k < i+j; k++)
	{
		putchar(a[k]);
	}

	return 0;
}
