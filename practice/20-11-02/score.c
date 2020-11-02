#include <stdio.h>

int main(void)
{
	int n[5], a[5], b[5], c[5];
	
	float avr[5];
	
	for (size_t i = 0; i < 5; i++)
	{
		printf("Please input the serial number of Student %d: ", i+1);
		scanf("%d", &n[i]);
		printf("Please input the three scores of Student %d, separated by space.\n", i+1);
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		
		avr[i] = (a[i] + b[i] + c[i]) / 3.0;
	}

	for (size_t i = 0; i < 5; i++)
	{
		printf("The serial number of Student %d is %d, the scores are %d.00 %d.00 %d.00, the average score is %2.2f\n", i+1, n[i], a[i], b[i], c[i], avr[i]);
	}

	return 0;
}
