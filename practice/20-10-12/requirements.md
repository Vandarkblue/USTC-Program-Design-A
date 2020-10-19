# 第一次上机

1. 编写程序实现以下输出

// helloWorld.c

```
**********
Hello World!
********** 
```

2. 下列程序为输入三个数并输出三个数中的最大者，输入并运行该程序，检查结果是否正确，如不正确，分析原因并进行修改。

// maximum.c

```c
#include<stdio.h>
main()
{
	int a,b,c,max;
	printf("Enter a:");
	scanf("%d",&a);
	printf("Enter b:");
	scanf("%d",&b);
	printf("Enter c:");
	scanf("%d",&c);
	max=a;
	if(max<b)		max=b;
	if(max<c)		max=c;
	printf(“max=%d\n”,max);
}
```

3. 下列程序为输入三角形的三条边边长，求三角形的面积，输入并运行该程序，检查结果是否正确，如不正确，分析原因并进行修改。

// triangle.c

```c
#include<stdio.h>
main()
{
	double a,b,c,s,area;
	printf("input a:");
	scanf("%lf",&a);
	printf("input b:");
	scanf("%lf",&b);
	printf("input c:");
	scanf("%lf",&c);
	s=(a+b+c)/2.0;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	printf("a=%6.2f,b=%6.2f,c=%6.2f\n",a,b,c);
	printf("s=%-8.2f,b=%-8.2f\n",s,area);
}
```

4. 编写程序实现输入两个整数，求这两个数的乘积和余数并输出。

// prodAndRmn.c

5. 编写程序计算圆柱体体积，圆柱体半径R和高度H由键盘输入。

// column.c
