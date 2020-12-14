#include <string.h>

void strSortSelect(int strc, char *strv[])
{
	int min;
	char *pointer = NULL;
	for (int i = 0; i < strc - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < strc; j++)
		{
			if (strcmp(strv[min], strv[j]) > 0)
			{
				min = j;
			}
			
		}
		if (min == i)
		{
			continue;
		}
		pointer = strv[min];
		strv[min] = strv[i];
		strv[i] = pointer;
	}
	return;
}

void strSortBubble(int strc, char *strv[])
{
	char *pointer = NULL;
	for (int i = 0; i < strc - 1; i++)
	{
		for (int j = 0; j < strc - i - 1; j++)
		{
			if (strcmp(strv[j], strv[j+1]) > 0)
			{
				pointer = strv[j];
				strv[j] = strv[j+1];
				strv[j+1] = pointer;
			}
			
		}
		
	}
	
}
