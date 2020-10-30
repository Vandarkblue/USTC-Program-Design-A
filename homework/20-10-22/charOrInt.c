/* charOrInt -- Tan Haoqiang page 82 task 8 */

/* Answers
	1. Both are okay.
	2. As below, Line 21.
	3. No. A integer is 4-byte long.
*/

#include <stdio.h>

/* Define the number of chars */
#define LENGTH 2

int main(void)
{
	int c[LENGTH]; // Predefine

	/* Input */
	for (size_t i = 0; i < LENGTH; i++)
	{
		printf("c%d = ", i+1);
		c[i] = getchar();
		getchar();
	}
	
	/* putchar() */
	for (size_t i = 0; i < LENGTH; i++) putchar(c[i]);
	putchar('\n');

	/* printf() */
	for (size_t i = 0; i < LENGTH; i++) printf("%c",c[i]);
	printf("\n");

	/* Print ASCII */
	for (size_t i = 0; i < LENGTH; i++) printf("%d ",c[i]);
	printf("\n");

	return 0;
}
