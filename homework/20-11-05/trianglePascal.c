/* trianglePascal.c -- Tan Haoqiang pgae 165 task 6 */
/* Ugly code, however it works. */

#include <stdio.h>

#define COUNT 10

int main(void)
{
	int a[(COUNT+2)*(COUNT+3)/2] = {1}; /* Don't touch this line*/

	/* I've got no idea what these fucking fomulae mean since I've finished them, so don't ask me */
	for (size_t i = 2; i < COUNT + 2; i++)
	{
		for (size_t j = 2; j < i; j++)
		{
			a[i*(i+1)/2+j] = a[(i-1)*i/2+j-1] + a[(i-1)*i/2+j];
			printf("%6d ", a[i*(i+1)/2+j]);
		}
		a[i*(i+3)/2] = 1;
		printf("%6d\n", 1);

	}

	return 0;
}
