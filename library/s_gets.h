#ifndef _S_GETS_H_
#define _S_GETS_H_

#ifndef inputIntegerObject
#define inputIntegerObject "Node"
#endif

#include <stdbool.h>
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

void inputInteger(int num, int *object, char name[])
{
	// printf("Input the score of student %d: ", num);
	printf("Input the ");
	printf(name);
	printf(" of %s %d: ", inputIntegerObject, num);
	while (true)
	{
		if (scanf("%d", object))
		{
			break;
		}
		else
		{
			fflush(stdin);
			printf("Input the ");
			printf(name);
			printf(" of %s %d: ", inputIntegerObject, num);
		}
	}
	return;
}

#endif
