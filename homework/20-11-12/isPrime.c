/* isPrime.c -- Tan Haoqiang Page 215 Task 3 */
/* ------------------------------------ */
/*   Licensed under the MIT License     */
/*  Copyright (c) 2020 Dec.Randomizer   */
/* ------------------------------------ */
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

_Bool isPrime(size_t num)
{
	if (num == 3)
	{
		return 1;
	}
	else for (size_t i = 3; i < (int)sqrt(num); i+=2)
	{
		if (num % i == 0)
		{
			printf("%u is a factor of %u.\n", i, num);
			return 0;
		}
		
	}
	return 1;
}
