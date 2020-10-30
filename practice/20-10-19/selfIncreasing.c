/* selfIncreasing.c -- Task 2 */

#include <stdio.h>

int main(void)
{
	int i, j, m, n;

	i=8; j=10;
	m=++i; n=j++;
	
	printf("%d, %d, %d, %d\n",i,j,m,n);	// 9, 11, 9, 10

	return 0;
}
