#include <stdio.h>

int main(void)
{
	int x, y;
	
	x=4; y=3;

	printf("%d",(x>=y>=2)?1:0);	// 0

	return 0;
}
