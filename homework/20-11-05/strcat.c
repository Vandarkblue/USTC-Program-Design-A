/* stract.c -- Tan Haoqiang pgae 166 task 13 */

#include <stdio.h>

#define LENGTH 0xfffffff

char *udf_strcat(char *, char *);

int main(void)
{
	char a[LENGTH], b[LENGTH];

	printf("Input String A: ");
	gets(a);
	printf("Input String B: ");
	gets(b);

	puts(strcat(a, b));

	return 0;
}

/* udf as user-defined function, avoiding possible conflicts */
char *udf_strcat(char dest[], char addn[])
{
	size_t i = 1, j = 0, k = 0;
	while (dest[i] != '\0')
	{
		++i;
	}
	while (addn[j] != '\0')
	{
		dest[i+j] = addn[j];
		++j;
	}
	dest[i+j] = '\0';
	return dest;
}
