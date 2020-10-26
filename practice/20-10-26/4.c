#include<stdio.h>

int main(void)
{
	int score, i, b;
	char grade;

	while(1) {

		b = scanf("%d",&score);
		getchar();

		if(score>=0&&score<=100&&b) {

			i = score / 10;

			switch(i) {
				case 0:
				case 1:
				case 2:
				case 3:
				case 4:
				case 5: grade='E'; break;
				case 6: grade='D'; break;
				case 7: grade='C'; break;
				case 8: grade='B'; break;
				case 9:
				case 10:grade='A'; break;

			} // switch

			printf("%c,%d\n",grade,score); break; // break while

		} else printf("score is error!\n");

	} // while

	return 0;

}
