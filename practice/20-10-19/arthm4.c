#include <stdio.h>

int main(void)
{
	int a, b, c;

	a=3; b=4; c=5;

	printf("%d",!(a>b)&&!c||1);	// 1

	return 0;
}
