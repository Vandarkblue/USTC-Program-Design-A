/* countArticle.c -- Tan Haoqiang Page 166 Task 10 */
/* ------------------------------------ */
/*   Licensed under the MIT License     */
/*  Copyright (c) 2020 Dec.Randomizer   */
/* ------------------------------------ */

# include <stdio.h>

#define STR 80
#define LINE 3

char *strcat(char *, char *);
int count(char src[], int obj);

int main(void)
{
	char s[STR], a[LINE*STR];
	for (size_t i = 0; i < LINE; i++)
	{
		gets(s);
		strcat(a, s);
	}
	printf("There are:\n");
	printf("%6d uppercase letters,\n", count(a, 2));
	printf("%6d lowercase letters,\n", count(a, 1));
	printf("%6d digits,\n", count(a, 3));
	printf("%6d spaces and\n", count(a, 0));
	printf("%6d other characters.\n", count(a, -1));
	
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
	return dest; /* Consistent with string.h */
}

int count(char src[], int obj)
{
	/* i as cyclic variable, j as count variable */
	int i = 0, j = 0;

	switch (obj)
	{
	case 0: /* space */
		while (src[i] != '\0')
		{
			if (src[i] == ' ')
			{
				++j;
			}
			++i;
		}
		break;
	case 1: /* lowercase */
		while (src[i] != '\0')
		{
			if (src[i] > 'a' && src[i] < 'z')
			{
				++j;
			}
			++i;
		}
		break;
	case 2: /* uppercase */
		while (src[i] != '\0')
		{
			if (src[i] > 'A' && src[i] < 'Z')
			{
				++j;
			}
			++i;
		}
		break;
	case 3: /* number */
		while (src[i] != '\0')
		{
			if (src[i] > '0' && src[i] < '9')
			{
				++j;
			}
			++i;
		}
		break;
	case -1:
	default: /* other characters */
		while (src[i] != '\0')
		{
			if (
				src[i] != ' '
				&& !(src[i] > 'a' && src[i] < 'z')
				&& !(src[i] > 'A' && src[i] < 'Z')
				&& !(src[i] > '0' && src[i] < '9')
			)
			{
				++j;
			}
			++i;
		}
		break;
	}
	return j;
}
