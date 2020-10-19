#include <stdio.h>

int main()
{
    int r,h;
    double v, pi;
    printf("Input the radius of the base:");
    scanf("%d",&r);
    printf("Input the height of the column:");
    scanf("%d",&h);
    pi = 3.141592653589793;
    v = pi * h * r * r;
    printf("The volume of the column is %lf",v);
    return 0;
}
