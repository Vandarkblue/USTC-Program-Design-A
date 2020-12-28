#include <stdio.h>
#include <stdlib.h>

#define M 5
#define N 3

int main(void)
{
	int temp;
	int arr[M][N];
	int *o[N], *p[N], *q[N];
	char tempStr[0xff];
	FILE *pA;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			/* Here input score */
			arr[i][j] = 0 + N * i + j;
		}
	}

	pA = fopen("stud.txt", "w");
	for (int i = 0; i < M; i++)
	{
		temp = 0;
		for (int j = 0; j < N; j++)
		{
			temp += arr[i][j];
			fputs(itoa(arr[i][j], tempStr, 10), pA);
			fputc('	', pA);
		}
		fputs(itoa(temp, tempStr, 10), pA);
		fputc('\n', pA);
	}
	fclose(pA);
	return 0;
}
