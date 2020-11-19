/* findWordLongest.c -- Tan Haoqiang Page 216 Task 10 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *findWordLongest(char*);

int main(void)
{
	int len;
	char *p, *l, *k;

	/* Use malloc() to get a string */
	p = (char*)malloc(sizeof(char));
	gets(p);
	len = strlen(p);
	char str[len];
	for (size_t i = 0; i < len; i++)
	{
		str[i] = *p;
		p++;
	}

	l = findWordLongest(str);

	for (k = l; *k!=' '&&*k; k++)
	{
		putchar(*k);
	}
	putchar('\n');

	/* Free the memory */
	free(p);
	return 0;
}

char *findWordLongest(char str[])
{
	int len=0, maxLen=0, start=0, maxStart=0;
	for (size_t i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			if (len == 0) /* A new word starts */
			{
				start = i;
			}
			++len;
		}
		else
		{
			if (len > maxLen) /* The current word is the longest met one */
			{
				maxLen = len;
				maxStart = start;
			}
			len = 0;
		}
	}
	if (len > maxLen) /* The last word is the longest met one */
	{
		maxLen = len;
		maxStart = start;
	}
	return (str + maxStart);
}
