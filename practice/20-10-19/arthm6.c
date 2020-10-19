#include <stdio.h>

int main(void)
{
	int a=12;

	printf("%d",a+=a%=a*=a);	// 0

	return 0;
}
