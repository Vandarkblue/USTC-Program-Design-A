#include <stdio.h>
#include "strSortSelect.h"

void strPrintf(int, char**);

int main(void)
{   
    char *name[]={"Follow me", "BASIC", "Great Wall", "FORTRAN", "Computer"};
    int n = sizeof(name) / sizeof(name[0]);

    strSortBubble(n, name);
    strPrintf(n, name);

	return 0;
}

void strPrintf(int strc, char *strv[])
{
	for (int i = 0; i < strc; i++)
	{
		puts(strv[i]);
		putchar('\n');
	}
	return;
}
