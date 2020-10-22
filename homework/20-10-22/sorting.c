// Tan Haoqiang page 107 task 4

// PLease don't use so many if-elses like this in your code.

#include <stdio.h>

int main(void)
{
	int a, b, c;

	printf("Input a, b and c.\n");
	scanf("%d %d %d", &a, &b, &c);

	if (a > b && b > c)
	{
		printf("a=%d, b=%d, c=%d", a, b, c);

	} else if (a > c && c > b) {
		printf("a=%d, c=%d, b=%d", a, c, b);

	} else if (b > c && c > a) {
		printf("b=%d, c=%d, a=%d", b, c, a);

	} else if (b > a && a > c) {
		printf("b=%d, a=%d, c=%d", b, a, c);

	} else if (c > a && a> b) {
		printf("c=%d, a=%d, b=%d", c, a, b);

	} else {
		printf("c=%d, b=%d, a=%d", c, b, a);

	}

	return 0;
}
