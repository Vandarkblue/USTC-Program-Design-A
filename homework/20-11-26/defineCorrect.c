#include <stdio.h>
/* considering that x might be a polynomial */
#define f(x) ((x)*(x))

int main(void)
{
	int a=6, b=2;
	int c;

	c = f(a) / f(b);

	printf("%d", c);

	return 0;
}

/*
* Output:
* 9
*/
