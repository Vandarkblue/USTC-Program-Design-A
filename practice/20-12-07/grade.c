#include <stdio.h>

#define M 5
#define N 3

void extremum(int src[M][N], int *max[], int *min[])
{
	int score[M] = {0};
	int temp = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			score[i] += src[i][j];
		}
		
	}

	int h = 0, l = 0;
	for (int i = 1; i < M; i++)
	{
		if (score[i] > score[h])
		{
			h = i;
		}
		if (score[i] < score[l])
		{
			l = i;
		}
		
	}

	for (int i = 0; i < M; i++)
	{
		if (score[i] == score[h])
		{
			// printf("max: ");
			// printf("arr[%d] ", i);
			max[temp] = src[i];
			++temp;
		}
	}
	// putchar('\n');

	temp = 0;
	for (int i = 0; i < M; i++)
	{
		if (score[i] == score[l])
		{
			// printf("min: ");
			// printf("arr[%d] ", i);
			min[temp] = src[i];
			++temp;
		}
	}
	// putchar('\n');

	return;
}

void sort(int src[M][N], int *dest[])
{
	int score[M];
	int p[M];
	int temp;

	for (int i = 0; i < M; i++)
	{
		score[i] = 0;
		for (int j = 0; j < N; j++)
		{
			score[i] += src[M][N];
		}
		
	}

	for (int i = 0; i < M; i++)
	{
		p[i] = i;
	}

	for (int i = 0; i < M - 1; i++)
	{
		for (int j = 0; j < M - i - 1; j++)
		{
			if (score[j] > score[j+1])
			{
				temp = score[j];
				score[j] = score[j+1];
				score[j+1] = temp;

				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}

	temp = 0;
	for (int i = 0; i < M; i++)
	{
		// printf("arr[%d] ", p[i]);
		dest[temp] = src[p[i]];
		++temp;
	}
	// putchar('\n');

	return;
}

int main(void)
{
	int arr[M][N];
	int *o[N], *p[N], *q[N];

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = 0 + N * i + j;
			// printf("%d ", arr[i][j]);
		}
		// putchar('\n');
	}
	
	extremum(arr, o, p);
	sort(arr, q);
	for (int i = 0; i < M; i++)
	{
		printf("arr[%d] ", *q[i]/N);
	}
	
	return 0;
}
