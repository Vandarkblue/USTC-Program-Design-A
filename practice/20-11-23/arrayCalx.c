/* arrayCalx.c -- A simple array calculator */

/* ------------------------------------ */
/*   Licensed under the MIT License     */
/*  Copyright (c) 2020 Dec.Randomizer   */
/* ------------------------------------ */

#include <stdio.h>

#define SCALE 0xff

int arrayCalxInput(int*);
void arrayCalxPrint(int*, int);
int arrayCalxMaximum(int*, int);
int arrayCalxMinimum(int*, int);
float arrayCalxAverage(int*, int);
void arrayCalxSortBubble(int*, int);
void arrayCalxSortSelect(int*, int);
int arrayCalxFind(int*, int, int);
_Bool arrayCalxDelete(int*, int*, int);
_Bool arrayCalxIsSorted(int*, int);
void arrayCalxLogo();

int main(void)
{
	int arr[SCALE] = {0};
	int scale = 0;

	int key = -1;
	int temp = 0; 

	arrayCalxLogo();

	while (1)
	{
		printf("-----------------menu-----------------\n");
		printf("0. Exit\n");
		printf("1. Input array data\n");
		printf("2. Print the current array\n");
		printf("3. Find the max. and the min. value\n");
		printf("4. Find the average value\n");
		printf("5. Bubble sort\n");
		printf("6. Select sort\n");
		printf("7. Find an element\n");
		printf("8. Delete an element\n");
		printf("9. Examine whether the array is sorted\n");
		printf("--------------------------------------\n");

		if (scanf("%d", &key))
		{
			switch (key)
			{
			case 0:
				printf("Exit\n");
				arrayCalxLogo();
				return 0;
			case 1:
				scale = arrayCalxInput(arr);
				break;
			case 2:
				printf("--------------------------------------\n");
				arrayCalxPrint(arr, scale);
				break;
			case 3:
				printf("--------------------------------------\n");
				if (!scale)
				{
					printf("NULL\n");
				}
				else
				{
					key = arrayCalxMaximum(arr, scale);
					temp = arrayCalxMinimum(arr, scale);
					printf("Max == arr[%d] == %d\n", key, arr[key]);
					printf("Min == arr[%d] == %d\n", temp, arr[temp]);
				}
				break;
			case 4:
				printf("Avr = %f\n", arrayCalxAverage(arr, scale));
				break;
			case 5:
				printf("Bubble sort\n");
				arrayCalxSortBubble(arr, scale);
				break;
			case 6:
				printf("Select sort\n");
				arrayCalxSortSelect(arr, scale);
				break;
			case 7:
				while (1)
				{
					printf("Input the integer to find: ");
					if (scanf("%d", &key))
					{
						temp = arrayCalxFind(arr, scale, key);

						if (temp == -1)
						{
							printf("Not found.\n");
						}
						else
						{
							printf("Integer %d is arr[%d]\n", key, temp);
						}
						break;
					}
					else
					{
						fflush(stdin);
					}	
				}
				break;
			case 8:
				while (1)
				{
					printf("Input the integer to delete: ");
					if (scanf("%d", &key))
					{
						temp = (int)arrayCalxDelete(arr, &scale, key);

						if (temp)
						{
							printf("Not found.\n");
						}
						else
						{
							printf("Integer %d has been removed\n", key);
						}
						break;
					}
					else
					{
						fflush(stdin);
					}
				}
				break;
			case 9:
				temp = (int)arrayCalxIsSorted(arr, scale);

				printf("Whether sorted: ");
				if (temp)
				{
					printf("True\n");
				}
				else
				{
					printf("False\n");
				}
				break;
			default:
				printf("Function not defined\n");
				break;
			} // switch(key)
		} // if input correct
		else
		{
			printf("Menu accepts integers only\n");
			fflush(stdin);
		}
	} // while true
	return 0;
}

/* input an integer each line, EOF for end, return the actual scale of array */
int arrayCalxInput(int arr[])
{
	int i = 0;
	int input = 0;

	printf("Input in sequence, ctrl+z for end\n");
	printf("--------------------------------------\n");
	for (i = 0; i < SCALE; ++i)
	{
		printf("arr[%d] = ", i);
		input = scanf("%d", arr+i);
		if (input == EOF)
		{
			return i;
		}
		if (!input)
		{
			--i;
		}
	}
	return i;
}

/* Print all of the elements in sequence */
void arrayCalxPrint(int arr[], int scale)
{
	if (scale == 0)
	{
		printf("NUll");
	}
	for (int i = 0; i < scale; i++)
	{
		printf("arr[%d] == %d\n", i, arr[i]);
	}
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

void arrayCalxSortSelect(int arr[], int scale)
{
	int min;
	for (int i = 0; i < scale - 1; i++)
	{
		min = i; /* Assume arr[i] is the minimum */
		for (int j = i+1; j < scale; j++)
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
_Bool arrayCalxDelete(int arr[], int *scale, int obj)
{
	int dest = arrayCalxFind(arr, *scale, obj);
	if (dest == -1)
	{
		return 1;
	}
	for (size_t i = dest; i < *scale - 1; i++)
	{
		arr[i] = arr[i+1];
		/* *(arr+i) = *(arr+i+1) <- Using pointer as requested */
	}
	--*scale;
	return 0;
}

/* Return 1 for sorted, 0 for not */
_Bool arrayCalxIsSorted(int arr[], int scale)
{
	if (scale == 0)
	{
		return 0;
	}
	for (int i = 0; i < scale-1; i++)
	{
		if (arr[i] > arr[i+1])
		{
			return 0;
		}
	}
	return 1;
}

void arrayCalxLogo(void)
{
	printf("  __   ____  ____   __   _  _  ___   __   __    _  _ \n");
	printf(" / _\\ (  _ \\(  _ \\ / _\\ ( \\/ )/ __) / _\\ (  )  ( \\/ )\n");
	printf("/    \\ )   / )   //    \\ )  /( (__ /    \\/ (_/\\ )  ( \n");
	printf("\\_/\\_/(__\\_)(__\\_)\\_/\\_/(__/  \\___)\\_/\\_/\\____/(_/\\_)\n");
	return;
}
