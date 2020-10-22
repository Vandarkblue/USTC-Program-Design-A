// Tan Haoqiang page 82 task 6 

#include <stdio.h>

int main(void)
{
	int c1, c2, c3, c4, c5;

	c1='C'; c2='h'; c3='i'; c4='n'; c5='a';
	
	c1 = encode(c1);
	c2 = encode(c2);
	c3 = encode(c3);
	c4 = encode(c4);
	c5 = encode(c5);

	putchar(c1);
	putchar(c2);
	putchar(c3);
	putchar(c4);
	putchar(c5);
	putchar('\n');

	printf("%c%c%c%c%c\n",c1,c2,c3,c4,c5);
	
	return 0;
}

int encode(int cx)
{
	if (cx>=65 && cx<=86 || cx>=97 && cx<=118)
	{
		return cx+4;
	} else if (cx>=87 && cx<=90 || cx>= 119 && cx<=122)
	{
		return cx-22;
	} else
	{
		return cx;
	}
}
