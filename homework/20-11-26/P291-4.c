#include <stdio.h>

int main(void)
{
	int m, n;
	printf("Input n: ");
	scanf("%d", &n);
	printf("Input m: ");
	scanf("%d", &m);

	int num[n], temp[m];
	int *p = num, *r = temp;

	for (int i = 0; i < n; i++)
	{
		printf("Input Num-%d: ", i+1);
		scanf("%d", p++);
	}
	p = num + n - m;
	for (int i = 0; i < m; i++)
	{
		*r++ = *p++;
	}
	p = num + n;
	for (int i = 0; i < n - m; i++)
	{
		--p;
		*p = *(p-m);
	}
	p = num;
	r = temp;
	for (int i = 0; i < m; i++)
	{
		*p++ = *r++;
	}
	p = num;
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *p++);
	}
	return 0;
}
