#include <stdio.h>
#include <string.h>

#define LEN 0xff
#define NUM 0xf

int findWordLongest(char*, char**);

int main(void)
{
	char src[LEN];
	char *dest[NUM] = {NULL};
	int lengthWord = 0;

	gets(src);

	lengthWord = findWordLongest(src, dest);

	for (int i = 0; dest[i] != NULL && i < NUM; i++)
	{
		for (int j = 0; j < lengthWord; j++)
		{
			putchar(*(dest[i]+j*sizeof(char)));
		}
		putchar(' ');
	}
	putchar('\n');

	return 0;
}

int findWordLongest(char src[], char *dest[])
{
	int len=0, lenMax=0, start=0, sequence=0;

	for (int i = 0; src[i]; i++)
	{
		if (src[i] >= 'a' && src[i] <= 'z' || src[i] >= 'A' && src[i] <= 'Z')
		{
			if (len == 0)
			{
				start = i;
			}
			++len;
		}
		else
		{
			if (len == lenMax)
			{
				dest[sequence] = &src[start];
				++sequence;
			}
			else if (len > lenMax)
			{
				lenMax = len;
				sequence = 1;
				dest[0] = &src[start];
				for (int j = 1; dest[j] != NULL; j++)
				{
					dest[j] = NULL;
				}
				
			}
			len = 0;
		}
		
	}
	if (len == lenMax)
	{
		dest[sequence] = &src[start];
		++sequence;
	}
	if (len > lenMax)
	{
		lenMax = len;
		sequence = 0;
		dest[0] = &src[start];
		for (int j = 1; dest[j] != NULL; j++)
		{
			dest[j] = NULL;
		}

	}
	return lenMax;
}
