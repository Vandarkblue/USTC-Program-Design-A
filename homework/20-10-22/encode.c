/* encode.c -- Tan Haoqiang page 82 task 6 */

/* Output:
	Glmre
	Glmre
*/

#include <stdio.h>

int main(void)
{
	/* Predefine */
	int encode();
	int c[] = {'C','h','i','n','a'};

	/* Calculate and output by putchar() */
	for (size_t i = 0; i < sizeof(c)/4; i++) putchar(encode(c[i]));
	putchar('\n');

	/* Calculate and output by printf() */
	for (size_t i = 0; i < sizeof(c)/4; i++) printf("%c",encode(c[i]));
	printf("\n");

	return 0;
}

int encode(int cx) /* Shift each letter 4 positions down */
{
	if (cx>=65 && cx<=86 || cx>=97 && cx<=118) return cx+4; // from a to x
	else if (cx>=87 && cx<=90 || cx>= 119 && cx<=122) return cx-22; // from w to z
	else return cx; // not a letter
}
