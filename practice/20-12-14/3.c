#include <stdio.h>
#include <stdlib.h>

void arrayCalxSortSelect(int arr[], int);

int main(int argc, char *argv[])
{
	int arr[argc - 1];
	int sum = 0;

	if (argc < 3)
	{
		printf("Input 2 or more integers.\n");
		return -1;
	}
	
	for (int i = 0; i < argc - 1; i++)
	{
		arr[i] = atoi(argv[i+1]);
		sum += arr[i];
	}
	printf("sum == %d\n", sum);

	printf("avr == %lf\n", (double)sum/(argc-1));

	arrayCalxSortSelect(arr, argc - 1);
	printf("In sequence: ");
	for (int i = 0; i < argc - 1; i++)
	{
		printf("%6d", arr[i]);
	}
	
	return 0;
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
