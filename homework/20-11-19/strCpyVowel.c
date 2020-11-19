/* strCpyVowel.c -- Tan Haoqiang Page 216 Task 7 */

#include <stdio.h>

char *strCpyVowel(char*, char*); 

/* This part dose not matter */
int main(void)
{
	char a[40], b[40];

	gets(a);
	strCpyVowel(b, a);

	puts(b);

	return 0;
}

char *strCpyVowel(char dest[], char src[])
{
	int k = 0;
	/* Vowel character table sorted by frequncy */
	char v[] = {'e', 'a', 'o', 'i', 'u', 'E', 'A', 'O', 'I', 'U'};
	while (*src != '\0') /* Check a character in src[] */
	{
		for (size_t i = 0; i < 10; ++i) /* See whether it is a vowel */ 
		{
			if (*src == v[i])
			{
				*dest++ = v[i]; /* Put it into dest[] */
				break;
		/* If a character is a vowel, it cannot be another */
			}
		}
		++src; /* Check the next */
	}
	return dest;
}
