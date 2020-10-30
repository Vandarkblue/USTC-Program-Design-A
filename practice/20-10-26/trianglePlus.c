/* trianglePlus.c -- Task 2 */

#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b, c, s, area, e, f, g;

	printf("input a:");
	scanf("%lf", &a);
	printf("input b:");
	scanf("%lf", &b);
	printf("input c:");
	scanf("%lf", &c);

	if(a+b>c&&a+c>b&&c+b>a) // As `../20-10-12/triangle.c`
	{	
		s = (a+b+c)/2.0;
		area = sqrt(s*(s-a)*(s-b)*(s-c));
		e = a*a + b*b - c*c;
		f = b*b + a*a - c*c;
		g = c*c + a*a - b*b;
		if (e>f) e = f;
		if (e>g) e = g;

		printf("a=%6.2f, b=%6.2f, c=%6.2f\n", a, b, c);

		if (e>0) printf("This is a sharp triangle.\n");
		else if (e==0) printf("WOW This is an amazing right triangle.\n");
		else printf("This is a blunt triangle.\n");
		printf("area = %-8.2f\n", s, area);

	} else printf("Cannot form a triangle.");

	return 0;
}
