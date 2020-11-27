#include <stdio.h>
/* assume that a and b are lvalues */
#define SWAP(a, b) {a=a^b; b=a^b; a=a^b;}

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);

	SWAP(a, b);
	printf("%d %d", a, b);

	return 0;
}
