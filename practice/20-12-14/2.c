#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Student
{
	int num;
	int age;
	float score;
};

int structInput(struct Student*, int);
void structPrint(struct Student*, int);
void structSort(struct Student*, int);

int main(void)
{
	int scale, num;
	struct Student *arr = NULL;
	bool correctInput = false;

	printf("--------------------------------------\n");
	printf("Input scale: ");
	correctInput = (bool)scanf("%d", &scale);
	while (!correctInput)
	{
		fflush(stdin);
		printf("Input scale: ");
		correctInput = scanf("%d", &scale);
	}
	printf("--------------------------------------\n");

	arr = (struct Student*)malloc(scale*sizeof(struct Student));
	if (arr == NULL)
	{
		printf("Not enough memory.\n");
		return -1;
	}

	num = structInput(arr, scale);
	structSort(arr, num);
	structPrint(arr, num);

	return 0;
}

/* input an integer each line, EOF for end, return the actual scale of array */
int structInput(struct Student *arr, int scale)
{
	int i;
	int input, j, k;
	bool correctInput = false;

	printf("Input in sequence, Ctrl+Z for end\n");
	printf("--------------------------------------\n");
	for (i = 0; i < scale; ++i, ++arr)
	{
		printf("Input student[%d]:\n", i);
		printf("num = ");
		input = scanf("%d", &arr->num);
		printf("age = ");
		j = scanf("%d", &arr->age);
		printf("score = ");
		k = scanf("%f", &arr->score);
		if (!(input && j && k))
		{
			--i;
			--arr;
		}
	}
	printf("--------------------------------------\n");
	return i;
	/* Not really good. If you wrongtype one, you need to re-input all. */
}

/* Print all of the elements in sequence */
void structPrint(struct Student *arr, int scale)
{
	if (scale == 0)
	{
		printf("Null\n");
	}
	for (int i = 0; i < scale; i++, arr++)
	{
		printf("Student No.%d:\n", arr->num);
		printf("age == %d\n", arr->age);
		printf("score == %f\n\n", arr->score);
	}
	printf("--------------------------------------\n");
	return;
}

void structSort(struct Student *arr, int scale)
{
	int min;
	float temp;
	for (int i = 0; i < scale - 1; i++)
	{
		min = i; /* Assume arr[i] is the minimum */
		for (int j = i + 1; j < scale; j++)
		{
			if ((arr+i)->score > (arr+j)->score)
			{
				min = j;
			}
		}
		if (min != i)
		{
			(arr+i)->num ^= (arr+min)->num;
			(arr+min)->num ^= (arr+i)->num;
			(arr+i)->num ^= (arr+min)->num;
			(arr+i)->age ^= (arr+min)->age;
			(arr+min)->age ^= (arr+i)->age;
			(arr+i)->age ^= (arr+min)->age;
			temp = (arr+i)->score;
			(arr+i)->score = (arr+min)->score;
			(arr+min)->score = temp;
		}	
	}
	return;
}
