/* arrayCalx.c -- A simple array calculator */

/* ------------------------------------ */
/*   Licensed under the MIT License     */
/*  Copyright (c) 2020 Dec.Randomizer   */
/* ------------------------------------ */

#include "../../library/arrayCalx.h"

#define SCALE 0xff

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
				arrayCalxLogo();
				return 0;
			case 1:
				scale = arrayCalxInput(arr, SCALE);
				break;
			case 2:
				arrayCalxPrint(arr, scale);
				break;
			case 3:
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
	return -1;
}

void arrayCalxLogo(void)
{
	printf("  __   ____  ____   __   _  _  ___   __   __    _  _ \n");
	printf(" / _\\ (  _ \\(  _ \\ / _\\ ( \\/ )/ __) / _\\ (  )  ( \\/ )\n");
	printf("/    \\ )   / )   //    \\ )  /( (__ /    \\/ (_/\\ )  ( \n");
	printf("\\_/\\_/(__\\_)(__\\_)\\_/\\_/(__/  \\___)\\_/\\_/\\____/(_/\\_)\n");
	return;
}
