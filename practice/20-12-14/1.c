#include <stdlib.h>
#include "../../library/arrarCalx.h"

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
