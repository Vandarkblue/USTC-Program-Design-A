#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arrayCalxInput(int*, int);
void arrayCalxPrint(int*, int);

int main(void)
{
	int scale, num;
	bool correctInput = 0;
	int *arr = false;

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

	arr = (int*)malloc(scale*sizeof(int));
	if (arr == NULL)
	{
		printf("Not enough memory.\n");
		return -1;
	}

	arrayCalxPrint(arr, scale);

	num = arrayCalxInput(arr, scale);

	arrayCalxPrint(arr, num);

	return 0;
}

/* input an integer each line, EOF for end, return the actual scale of array */
int arrayCalxInput(int *arr, int scale)
{
	int i = 0;
	int input = 0;

	printf("Input in sequence, Ctrl+Z for end\n");
	printf("--------------------------------------\n");
	for (i = 0; i < scale; ++i, ++arr)
	{
		printf("arr[%d] = ", i);
		input = scanf("%d", arr);
		if (input == EOF)
		{
		printf("--------------------------------------\n");
			return i;
		}
		if (!input)
		{
			--i;
			--arr;
		}
	}
	printf("--------------------------------------\n");
	return i;
}

/* Print all of the elements in sequence */
void arrayCalxPrint(int *arr, int scale)
{
	if (scale == 0)
	{
		printf("NULL\n");
	}
	for (int i = 0; i < scale; i++, arr++)
	{
		printf("arr[%d] == %d\n", i, *arr);
	}
	printf("--------------------------------------\n");
	return;
}
