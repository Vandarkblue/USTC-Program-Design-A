#include <stdio.h>

int main()
{
    int a,b,prod,rmn;
    printf("input a:");
    scanf("%d",&a);
    printf("input b:");
    scanf("%d",&b);
    prod = a * b;
    rmn = a % b;
    printf("The product is %d and the remainder is %d",prod,rmn);
    return 0;
}
