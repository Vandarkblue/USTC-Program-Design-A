#include <stdio.h>

int main(void)
{
	int n, m, count, remained;


	/* kill one each m */
	printf("Input n: ");
	scanf("%d", &n);
	printf("Input m: ");
	scanf("%d", &m);
	remained = n;

	_Bool flag[n];
	for (int i = 0; i < n; i++)
	{
		*(flag+i) = 0;
	}

	count = 0;

	while (remained > 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (!*(flag+i))
			{
				if (count == m-1)
				{
					count = 0;
					*(flag+i) = 1;
					--remained;

				} // to kill
				else
				{
					++count;

				} // not to kill
				
			} // if alive
			
		} // for each killed or alive
		
	} // while more than 1 remain

	/* find the last one */
	count = 0;
	while (*(flag+count))
	{
		++count;
	}
	printf("%d", count+1);

	return 0;
}
