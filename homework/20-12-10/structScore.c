/* structScore.c -- Tan Page 330 Task 5 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define NUM_STU 5

struct Score
{
	int scientiaComputatri;
	int linguaJaponica;
	int doctrinaMilitaris;

};

struct Student
{
	int id;
	char name[0x1f];
	struct Score score;
	float scoreAvr;

};

int main(void)
{
	struct Student student[NUM_STU];

	float scoreAvrTotal = 0;
	float scoreAvrMax = 0;

	/* Sample names */
	strcpy(student[0].name, "Billy Herrington");
	strcpy(student[1].name, "Van Darkholme");
	strcpy(student[2].name, "Ikariya Biollante");
	strcpy(student[3].name, "Gosaku Kamata");
	strcpy(student[4].name, "Kazuya Kiyoshi");
	for (int i = 0; i < NUM_STU; i++)
	{
		student[i].id = i;
		/* Sample scores */
		student[i].score.scientiaComputatri = 3*i;
		student[i].score.linguaJaponica = 3*i + 1;
		student[i].score.doctrinaMilitaris = 3*i + 2;
		// printf("Input name[%d]: ", i);
		// scanf("%s", student[i].name);
	}
	for (int i = 0; i < NUM_STU; i++)
	{
		student[i].scoreAvr = (
			student[i].score.scientiaComputatri
			+ student[i].score.linguaJaponica
			+ student[i].score.doctrinaMilitaris
		) / 3.0;
		scoreAvrTotal += student[i].scoreAvr;
		if (student[i].scoreAvr > scoreAvrMax)
		{
			scoreAvrMax = student[i].scoreAvr;
		}
		
	}
	scoreAvrTotal /= NUM_STU;
	printf("scoreAvrTotal = %f\n---\n", scoreAvrTotal);

	for (int i = 0; i < NUM_STU; i++)
	{
		if (fabs(student[i].scoreAvr - scoreAvrMax) < 0.1)
		{
			printf("ID.%d - ", student[i].id);
			puts(student[i].name);
			printf("score.scientiaComputatri = %d\n", student[i].score.scientiaComputatri);
			printf("score.linguaJaponica = %d\n", student[i].score.linguaJaponica);
			printf("score.doctrinaMilitaris = %d\n", student[i].score.doctrinaMilitaris);
		}
		
	}
	

	return 0;
}
