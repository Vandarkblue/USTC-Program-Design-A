// Tan Haoqiang page 82 task 8

/* Answers
	1. Both are okay.
	2. As below, Line 21.
	3. No. A integer is 4-byte long.
*/

#include <stdio.h>

int main(void)
{
	char c1, c2;

	printf("c1 = ");
	c1 = getchar();
	getchar();
	printf("c2 = ");
	c2 = getchar();

	putchar(c1);
	putchar(c2);
	putchar('\n');

	printf("%c%c\n",c1,c2);

	// Print ASCII
	printf("%d,%d\n",c1,c2);

	return 0;
}
