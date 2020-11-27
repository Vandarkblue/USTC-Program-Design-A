#include <stdio.h>

/* the number of students */
#define N 5
/* the number of subjects */
#define M 3

int main(void)
{
	int id[N];

	double grade[N][M], average[N];
	
	for (int i = 0; i < N; i++)
	{
		printf("Please input the serial number of Student %d: ", i+1);
		scanf("%d", &id[i]);
		printf("Please input the %d scores of Student %d, separated by space.\n", M, i+1);
		for (int j = 0; j < M; j++)
		{
			scanf("%lf", &grade[i][j]);
			average[i] += grade[i][j];
		}
		
		average[i] /= (double)M;
	}

	for (int i = 0; i < N; i++)
	{
		printf("The serial number of Student %d is %8.2lf; the scores are ", i+1, id[i]);
		for (int j = 0; j < M; j++)
		{
			printf("%8.2lf, ", grade[i][j]);
		}
		printf("and the average score is %8.2f;\n", average[i]);
	}

	return 0;
}
