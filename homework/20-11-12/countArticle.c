/* countArticle.c -- Tan Haoqiang Page 166 Task 10 */

#include <stdio.h>

#define STR 80
#define LINE 3

char *strcat(char*, char*);
int *countArticle(char src[], int dest[]);

int main(void)
{
	char s[STR], a[LINE*STR];
	int count[5];
	for (size_t i = 0; i < LINE; i++)
	{
		gets(s);
		strcat(a, s);
	}
	
	countArticle(a, count);

	printf("There are:\n");
	printf("%6d uppercase letters,\n", count[0]);
	printf("%6d lowercase letters,\n", count[1]);
	printf("%6d digits,\n", count[2]);
	printf("%6d spaces and\n", count[3]);
	printf("%6d other characters.\n", count[4]);

	return 0;
}

/* From homework\20-11-05\strcat.c */
char *strcat(char dest[], char addn[])
{
	size_t i = 1, j = 0, k = 0;

	while (dest[i] != '\0')
	{
		++i;
	}
	while (addn[j] != '\0')
	{
		dest[i+j] = addn[j];
		++j;
	}
	/* Consistent with string.h */
	return dest;
}

/* The length of int_dest[] is at least 5 */
int *countArticle(char src[], int dest[])
{
	/* i as cyclic variable */
	int i = 0;

	while (src[i] != '\0')
	{
		if (src[i] > 'A' && src[i] < 'Z')
		{
			++dest[0];
		}
		else if (src[i] > 'a' && src[i] < 'z')
		{
			++dest[1];
		}
		else if (src[i] > '0' && src[i] < '9')
		{
			++dest[2];
		}
		else if (src[i] == ' ')
		{
			++dest[3];
		}
		else
		{
			++dest[4];
		}
		++i;
	}
	return dest;
}
