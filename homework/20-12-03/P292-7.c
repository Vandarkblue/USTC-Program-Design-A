#include <stdio.h>

/* Copy string src[] to dest[] omitting the starting `omitted` words. dest[] should be of proper scale. Return -1 for Error, otherwise 0. */
int strCpyPart(char dest[], char src[], int omitted)
{
	int length = 0;
	while (*(src + length) != '\0')
	{
		++length;
	}
	if (omitted >= length)
	{
		*dest = '\0';
		return -1;
	}
	src += omitted;
	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return 0;
}

int main(void)
{
	char a[] = "Deep Dark Fantasy.";
	char b[sizeof(a)/sizeof(a[0])] = "\0";

	strCpyPart(b, a, 5);
	puts(b);

	return 0;
}
