#include <stdio.h>

#define MAX_LENGTH 0xff

int udf_strLength(char str[])
{
	int i = 0;
	while (*(str + i) != '\0')
	{
		++i;
	}
	return i;
}

int main(void)
{
	char a[MAX_LENGTH];

	gets(a);

	printf("%d\n", udf_strLength(a));

	return 0;
}
