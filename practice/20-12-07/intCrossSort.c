#include "../../library/arrarCalx.h"

#define N 10

void crossSort(int**, int*);

int main(void)
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *dest[sizeof(arr)/sizeof(arr[0])];

	for (int i = 0; i < N; i++)
	{
		dest[i] = arr + i;
	}
	
	crossSort(dest, arr);

	// for (int i = 0; i < N; i++)
	// {
	// 	printf("b[%d] = %d; ", i, *dest[i]);
	// }
	
	return 0; 
}

void crossSort(int *dest[N], int srcv[N])
{
	int *oddv[N], *evenv[N];
	int oddc = 0, evenc = 0;
	for (int i = 0; i < N; i++)
	{
		if (srcv[i] % 2)
		{
			oddv[oddc] = srcv + i;
			++oddc;
		}
		else
		{
			evenv[evenc] = srcv + i;
			++evenc;
		}
		
	}

	arrayCalxSortBubbleP(oddv, oddc);
	arrayCalxSortBubbleP(evenv, evenc);

	for (int i = 0; i < oddc; i++)
	{
		*(dest + i) = *(oddv + i);
	}
	for (int i = 0; i < evenc; i++)
	{
		*(dest + N - i - 1) = *(evenv + i);
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d ", *dest[i]);
	}
	
	return;
}
