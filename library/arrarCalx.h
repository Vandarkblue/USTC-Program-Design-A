#include <stdio.h>
#include <stdbool.h>

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

/* Return the subscript of the maximal element, -1 for null */
int arrayCalxMaximum(int arr[], int scale)
{
	if (scale == 0)
	{
		return -1;
	}

	int maximum = arr[0];
	for (int i = 1; i < scale; i++)
	{
		if (arr[i] > arr[maximum])
		{
			maximum = i;
		}
	}
	return maximum;
}

/* Return the subscript of the minimal element, -1 for null */
int arrayCalxMinimum(int arr[], int scale)
{
	if (scale == 0)
	{
		return -1;
	}

	int minimum = arr[0];
	for (int i = 1; i < scale; i++)
	{
		if (arr[i] < arr[minimum])
		{
			minimum = i;
		}
	}
	return minimum;
}

/* Return the average of the array, -1 for null */
float arrayCalxAverage(int arr[], int scale)
{
	if (scale == 0)
	{
		return -1;
	}

	int sum = 0;
	for (size_t i = 0; i < scale; i++)
	{
		sum += arr[i];
	}
	return (float)sum/scale;
}

void arrayCalxSortBubble(int arr[], int scale)
{
	for (int i = 0; i < scale - 1; i++)
	{
		for (int j = 0; j < scale - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				arr[j] ^= arr[j+1];
				arr[j+1] ^= arr[j];
				arr[j] ^= arr[j+1];
			}
		}
	}
	return;
}

void arrayCalxSortBubbleP(int *arr[], int scale)
{
	int *temp = NULL;
	for (int i = 0; i < scale - 1; i++)
	{
		for (int j = 0; j < scale - i - 1; j++)
		{
			if (*arr[j] > *arr[j+1])
			{
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return;
}

void arrayCalxSortSelect(int arr[], int scale)
{
	int min;
	for (int i = 0; i < scale - 1; i++)
	{
		min = i; /* Assume arr[i] is the minimum */
		for (int j = i + 1; j < scale; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			arr[i] ^= arr[min];
			arr[min] ^= arr[i];
			arr[i] ^= arr[min];
		}	
	}
	return;
}

void arrayCalxSortSelectP(int *arr[], int scale)
{
	int min;
	int *temp = NULL;
	for (int i = 0; i < scale - 1; i++)
	{
		min = i; /* Assume arr[i] is the minimum */
		for (int j = i + 1; j < scale; j++)
		{
			if (*arr[min] > *arr[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}	
	}
	return;
}

/* Return the subscript of the object element, -1 for not found */
int arrayCalxFind(int arr[], int scale, int obj)
{
	for (size_t i = 0; i < scale; i++)
	{
		if (arr[i] == obj)
		{
			return i;
		}
	}
	return -1;
}

/* Return 0 for success, scale self-decreases. 1 for not found */
bool arrayCalxDelete(int arr[], int *scale, int obj)
{
	int dest = arrayCalxFind(arr, *scale, obj);
	if (dest == -1)
	{
		return true;
	}
	for (size_t i = dest; i < *scale - 1; i++)
	{
		arr[i] = arr[i+1];
		/* *(arr+i) = *(arr+i+1) <- Using pointer as requested */
	}
	--*scale;
	return false;
}

/* Return 1 for sorted, 0 for not */
bool arrayCalxIsSorted(int arr[], int scale)
{
	if (scale == 0)
	{
		return false;
	}
	for (int i = 0; i < scale-1; i++)
	{
		if (arr[i] > arr[i+1])
		{
			return false;
		}
	}
	return true;
}
