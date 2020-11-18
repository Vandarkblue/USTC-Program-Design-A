/* isPrime.c -- Tan Haoqiang Page 215 Task 3 */
/* Examine a integer whether being prime. */

#include <stdio.h>
#include <math.h>

_Bool isPrime(size_t);

int main(void)
{
	int a;

	printf("Input the integer: ");
	scanf("%ud", &a);

	printf("%u is %sa prime number.", a, isPrime(a)?"":"not ");
	
}

/* O(sqrt(n)) */
_Bool isPrime(size_t num)
{
	/* Small numbers claimed */
	if (num <= 1)
	{
		printf("Are there any problems with your brain?\n");
		return 0;
	}
	if (num == 2 || num == 3)
	{
		return 1;
	}
	/* Considering a larger prime number can only be (6n+1) or (6n-1) */
	if (!(num & 1)) /* Bit operation for mod 2 */
	{
		printf("2 is a factor of %d.\n", num);
		return 0;
	}
	if (num %3 == 0)
	{
		printf("3 is a factor of %d.\n", num);
		return 0;
	}
	
	int tmp = sqrt(num);
	/* Check sifted ones for sure */
	for (size_t i = 5; i <= tmp; i += 6)
	{
		if (num %i == 0)
		{
			printf("You know %d is a factor of %d. So ", i, num);
			return 0;
		}
		else if (num %(i+2) == 0)
		{
			printf("You know %d is a factor of %d. So ", i+2, num);
			return 0;
		}
	}
	/* Prime numbers left */
	return 1;
}
