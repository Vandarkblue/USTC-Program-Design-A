#include <stdio.h>

int main(void)
{
	int n = 65535;
	char a[n], b[n];

	printf("Please input string A:\n");
	gets(a);
	printf("Please input string B:\n");
	gets(b);

	int i = 0;
	while (a[i] == b[i] && a[i] != '\0' && b[i] != '\0')
	{
		++i;
	}
	printf("%d", a[i] - b[i]);
	
	return 0;
}
