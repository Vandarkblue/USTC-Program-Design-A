/* sumDiagonal.c -- Tan Haoqiang pgae 165 task 3 */

#include <stdio.h>

int main(void)
{
	int n;
	int s = 0;

	printf("The scale of the matrix is: ");
	scanf("%d", &n);
	getchar();

	int arr[n][n];

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			printf("The element in Row %d, Column %d is: ", i+1, j+1);
			scanf("%d", &arr[i][j]);
			getchar();
		}
		
	}

	for (size_t i = 0; i < n; i++)
	{
		s += arr[i][i];
	}

	printf("The diagonal sum is %d", s);

	return 0;
}
