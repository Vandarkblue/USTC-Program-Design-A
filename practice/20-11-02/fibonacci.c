/* fibonnacci.c --  */

#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	if (n > 92)
	{
		n = 92;
		printf("Too large.\n");
	}
	
/* we assume that at least 2 numbers are required */
	size_t a[n];
	a[0] = 1;
	a[1] = 1;

	printf("1 1 ");
	
	for (int i = 2; i < n; i++)
	{
		a[i] = a[i-2] + a[i-1];

		printf("%llu ", a[i]);
		
		if (i % 4 == 3)
		{
			putchar('\n');
		}

	} // for i

	return 0;
}
