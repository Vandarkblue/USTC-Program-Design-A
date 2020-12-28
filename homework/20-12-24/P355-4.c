/**
 * Put A.txt, B.txt and C.txt beside this.
 */

#include <stdio.h>

void sort(char name1[], char name2[], char obj[])
{
	int ch0, ctr, ptr;
	FILE *pA, *pB;
	pB = fopen(obj, "w");
	for (int asc = 0x1; asc < 0xff; asc++)
	{
		ctr = 0;
		pA = fopen(name1, "r");
		ch0 = getc(pA);
		while (ch0 != EOF)
		{
			if (ch0 == asc)
			{
				ctr++;
			}
			ch0 = getc(pA);
		}
		fclose(pA);
		pA = fopen(name2, "r");
		ch0 = getc(pA);
		while (ch0 != EOF)
		{
			if (ch0 == asc)
			{
				ctr++;
			}
			ch0 = getc(pA);
		}
		fclose(pA);
		for (int ptr = 0; ptr < ctr; ptr++)
		{
			putc(asc, pB);
		}
	}
	flocse(pB);
	return;
}

int main(void)
{
	sort("A.txt", "B.txt", "C.txt");
	return 0;
}
