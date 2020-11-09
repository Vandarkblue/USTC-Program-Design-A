#include <stdio.h>

int main(void)
{
	int del;
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Initialized

	/* Manual Input */
	// for (size_t i = 0; i < 10; i++)
	// {
	// 	printf("Please input integer %d: ", i+1);
	// 	scanf("%d", &a[i]);
	// }

	printf("Please input del_num: ");
	scanf("%d", &del);
	for (size_t i = 0; i < del - 1; i++)
	{
		printf("%d ", a[i]);
	}
	
	for (size_t i = del - 1; i < 9; i++)
	{
		a[i] = a[i+1];
		printf("%d ", a[i]);
	}
	return 0;
}
