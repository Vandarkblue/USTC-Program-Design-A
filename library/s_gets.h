#include <stdio.h>
#include <string.h>

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n'); // look for newline
		if (find)
		{
			*find = '\0'; // place a null character there
		} // if the address is not NULL
		else
		{
			while (getchar() != '\n')
			{
				continue; // dispose of the rest of line
			}
		} // else
	}
	return ret_val;
}
