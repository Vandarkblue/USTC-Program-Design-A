#include <stdio.h>

int main(void)
{
	size_t n;
	scanf("%d", &n);
	
	int a[n];
	a[0] = 1; a[1] = 1;
	
	for (size_t i = 0; i < n; i++)
	{
		if (i > 1)
		{
			a[i] = a[i-2] + a[i-1];
		}
		
		printf("%d ", a[i]);
		
		if (i % 4 == 3)
		{
			putchar('\n');
		}

	} // for i

	return 0;
}
