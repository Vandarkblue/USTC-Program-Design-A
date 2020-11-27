#include <stdio.h>
#include <string.h>

#define N 0xff

int main(void)
{
	char a[N], b[N], c[N];
	char *p=a, *q=b, *r=c;

	scanf("%s\n%s\n%s", p, q, r);

	switch ((int)(strcmp(p, q)>0) + 2*(int)(strcmp(q, r)>0)+ 2*(int)(strcmp(p, r)>0))
	{
	case 5:
		printf("%s\n%s\n%s\n", r, q, p);
		break;
	case 4:
		printf("%s\n%s\n%s\n", r, p, q);
		break;
	case 3:
		printf("%s\n%s\n%s\n", q, r, p);
		break;
	case 2:
		printf("%s\n%s\n%s\n", p, r, q);
		break;
	case 1:
		printf("%s\n%s\n%s\n", q, p, r);
		break;
	case 0:
		printf("%s\n%s\n%s\n", p, q, r);
		break;
	default:
		break;
	}

	return 0;
}
