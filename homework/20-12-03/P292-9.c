#include <stdio.h>

#define COLUMN 3
#define ROW 2

int *transpose(const int column, const int row, int dest[column][row], const int src[row][column])
{
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			dest[i][j] = src[j][i];
		}
		
	}
	return &dest[0][0];
}

int main(void)
{
	int k = 0;
	int a[ROW][COLUMN];
	int b[COLUMN][ROW];

	/* Generate a[][] */
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			a[i][j] = ++k;
		}
		
	}

	transpose(COLUMN, ROW, b, a);

	/* Print b[] i.e. a(^T)[] */
	for (int i = 0; i < COLUMN; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			printf("%d ", b[i][j]);
		}
		putchar('\n');
	}

	return 0;
}
