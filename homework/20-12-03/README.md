# 1203 作业

1. 将课上间的用指针数组对字符串排序的例题改为用冒泡排序法排序。

```c
main()
{   void sort(char  *name[],int n), print(char  *name[],int n);
    char *name[]={"Follow me","BASIC",
      "Great Wall","FORTRAN","Computer "};
    int n=5;
    sort(name,n);
    print(name,n);
}
void sort(char *name[],int n)
{   char *temp;
    int i,j,k;
    for(i=0;i<n-1;i++)
    {   k=i;
         for(j=i+1;j<n;j++)
	if(strcmp(name[k],name[j])>0)   k=j;
        if(k!=i)
       {  temp=name[i];  name[i]=name[k]; name[k]=temp;}
    }
}
```

2. 教材 P291-292 第 `6`、`7`、`9`、`15` 题。（仍然用指针加 `*` 的方式实现）
