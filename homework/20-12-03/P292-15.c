#include <stdio.h>
#include <stdbool.h>

#define STUDENTC 4
#define COURSEC 5
#define COURSES 0
#define NUMFAIL 2

/* Return the average score of Course_S. */
int avrCourse(int, int, int(*)[*], int);
/* Return the scale of dest[], i.e. the count of failed students. Failed as numFail courses failed. */
int stuFail(int, int, int(*)[*], int, int*);
/* Return 1 if average >= 90 or lowest >= 85 in student[], otherwise 0. */
_Bool avr90orAll85(int, int*);

int main(void)
{
	/* Randomly defined */
	int arr[STUDENTC][COURSEC] = {{84, 83, 82, 81, 80}, {86, 87, 88, 89, 90}, {80, 92, 93, 94, 95}, {5, 6, 7, 8, 9}};

	int numFail = 0;
	int failed[STUDENTC];

	int numRoll = 0;
	int rollking[STUDENTC];

	/* Print scores */
	// for (int i = 0; i < STUDENTC; i++)
	// {
	// 	for (int j = 0; j < COURSEC; j++)
	// 	{
	// 		printf("%d ", arr[i][j]);
	// 	}
	// 	putchar('\n');
	// }

	printf("---\n");
	printf("avr = %d\n", avrCourse(STUDENTC, COURSEC, arr, COURSES));
	printf("---\nFailed: ");

	numFail = stuFail(STUDENTC, COURSEC, arr, NUMFAIL, failed);

	for (int i = 0; i < numFail; i++)
	{
		printf("%d ", failed[i]);

	} // for each failed student

	printf("\n---\nOutstanding: ");
	for (int i = 0; i < STUDENTC; i++)
	{
		if (avr90orAll85(COURSEC, arr[i]))
		{
			printf("%d ", i);
		}
		
	} // for each student

	putchar('\n');

	return 0;

}

int avrCourse(int studentC, int courseC, int arr[studentC][courseC], int courseS)
{
	int sum = 0;

	for (int i = 0; i < studentC; i++)
	{
		sum += arr[i][courseS];
	}

	return (float)sum / courseC ;
}

int stuFail(int studentC, int courseC, int arr[studentC][courseC], int numFail, int *dest)
{
	int stuFailed = 0;
	int flagFail = 0;
	int scorePass = 60;

	for (int i = 0; i < studentC; i++)
	{
		flagFail = 0;
		for (int j = 0; j < courseC; j++)
		{
			if (arr[i][j] < scorePass)
			{
				++flagFail;
			}
			
		} // for each course

		if (flagFail >= numFail)
		{
			*dest = i;
			++dest;
			++stuFailed;

		} // if failed in numFail courses
		
	} // for each student

	return stuFailed;
}

_Bool avr90orAll85(int courseC, int student[courseC])
{
	_Bool flag85 = true;
	int sum = 0;

	for (int i = 0; i < courseC; i++)
	{
		if (student[i] < 85)
		{
			flag85 = false;
			break;
		}
		
	}
	if (flag85)
	{
		return true;

	} // if all over 85, else...

	for (int i = 0; i < courseC; i++)
	{
		sum += student[i];
	}
	if (sum >= courseC * 90)
	{
		return true;

	} // compare integer rather than float

	return false; // neither... nor...
}
