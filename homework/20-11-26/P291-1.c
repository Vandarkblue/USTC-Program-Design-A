#include <stdio.h>

int main(void)
{
	int a, b, c;
	int *p=&a, *q=&b, *r=&c;

	scanf("%d %d %d", p, q, r);

	switch ((*p>*q) + 2*(*q>*r)+ 2*(*p>*r))
	{
	case 5:
		printf("%d %d %d\n", *r, *q, *p);
		break;
	case 4:
		printf("%d %d %d\n", *r, *p, *q);
		break;
	case 3:
		printf("%d %d %d\n", *q, *r, *p);
		break;
	case 2:
		printf("%d %d %d\n", *p, *r, *q);
		break;
	case 1:
		printf("%d %d %d\n", *q, *p, *r);
		break;
	case 0:
		printf("%d %d %d\n", *p, *q, *r);
		break;
	default:
		break;
	}

	return 0;
}
