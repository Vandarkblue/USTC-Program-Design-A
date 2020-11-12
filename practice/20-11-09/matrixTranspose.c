/* matrixTranspose.c -- Task 4 */

#include <stdio.h>

int main(void)
{
	int a[3][3], b[3][2], c[3][2];
	int temp;

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			printf("Input a[%d][%d]:\n", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			printf("Input b[%d][%d]:\n", i, j);
			scanf("%d", &b[i][j]);
		}
	}	
	
	/* Fake transposing */
	printf("---------\nA transposed:\n");
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			printf("%d ", a[j][i]);
		}
		putchar('\n');
	}

	printf("---------\nC:\n");
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			temp = 0;
			for (size_t k = 0; k < 3; k++)
			{
				temp += a[i][k] * b[k][j];
			}
			c[i][j] = temp;
			printf("%d ", c[i][j]);
		}
		putchar('\n');
	}

	return 0;
}
