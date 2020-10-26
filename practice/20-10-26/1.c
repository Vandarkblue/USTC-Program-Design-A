#include <stdio.h>

int main(void)
{
    int a;
	
    while (a != 42) {

        scanf("%c",&a);

        if (a>='a'&&a<='z') printf("%c\n",a-'a'+'A');
        else if(a != 42) printf("Error Please try again\n");

        getchar();

    }

    return 0;

}
