/* errorDefine.c -- poor code example */
/* define before inlcude */
#define f(x) x*x
#include<stdio.h>
/* neither return type nor argument declairation */
main()
{
	/* no space next to the binary operators */
	int a=6,b=2,c;
	/* ERROR: unsafe macro define */
	c=f(a)/f(b);
	printf("%d", c);
	/* no return value, suck it */
}

/*
* Full of poor styles.
*
* Output:
* 36
* == 6*6/2*2
*/
