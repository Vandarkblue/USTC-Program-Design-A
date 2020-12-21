#include <stdio.h>
#include <math.h>
#include "../../library/baseConvert.h"

int main(void)
{
	int num;
	int command;

	scanf("%d", &num);
	scanf("%d", &command);

	baseConvert(num, command);

	return 0;
}
