#include <stdio.h>

int main(void)
{
	int a;
	double x, y;

	x = 2.5;
	a = 7;
	y =4.7;

	printf("%lf",x+a%3*(int)(x+y)%2/4);	//2.500000

	return 0;
}
