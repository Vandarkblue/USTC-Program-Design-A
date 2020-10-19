# Homework 20-10-15

> The homework this week: P80 1, 3, 4

The following programs are complied and running in `MinGW-W64-builds-4.3.5`.

1. 
```c
#include <stdio.h>
#include <math.h>

int main(void)
{
	int n=10; // for n years
	double r=0.07, p; // annual gorwth rate et the final multiple

	p = pow(r+1, n);
	printf("%2.2lf%%\n", 100*(p-1)); // print the percentage
	// 96.72%

	return 0;
}
```

3.
```c
#include <stdio.h>
#include <math.h>

int main(void)
{
	double d, p, r, m;
	d = 300000;
	p = 6000;
	r = 0.01;

	m = log(p/(p-d*r))/log(1+r);
	printf("%2.1lf\n", m); // MinGW automatically rounding
	// 69.7

	return 0;
}
```
<br/><br/><br/><br/><br/>
4.
(1) Output：
```c
c1=a,c2=b
c1=97,c2=98
```
`%c` -> character,ASCII. `%d` -> integer.

(2) Output：
```c
c1=?c2=?
c1=-59,c2=-58
```
`197` et `198` are `-59` et `-58` mod `256`. They are not standard ASCII values.

(3) Output：
```c
c1=a,c2=b
c1=97,c2=98
```
The same as (1).
