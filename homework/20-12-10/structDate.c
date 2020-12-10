/* structDate.c -- Tan Page 330 Task 1 */

#include <stdio.h>

/* Non-leap years */
const int dayCountInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* Negative annus value stands for (1 - how_many_years_before_1AD) */
struct date
{
	int annus;
	int mensis;
	int dies;
};

int dateLocateInYear(struct date);

int main(void)
{
	
	struct date date;

	scanf("%d %d %d", &date.annus, &date.mensis, &date.dies);
	
	// printf("%4d/%02d/%02d\n", date.annus, date.mensis, date.dies);

	printf("%d\n", dateLocateInYear(date));

	return 0;

}

/* Return -1 for incalculable */
int dateLocateInYear(struct date date)
{
	_Bool isLeapYear;
	int counter = 0;

	if (date.annus % 400 == 0)
	{
		isLeapYear = 1;
	}
	else if (date.annus % 100 == 0)
	{
		isLeapYear = 0;
	}
	else if (date.annus % 4 == 0)
	{
		isLeapYear = 1;
	}
	else
	{
		isLeapYear = 0;
	}
	
	if (date.mensis > 12 || date.mensis < 1)
	{
		return -1;
	}
	
	for (int i = 0; i < date.mensis - 1; i++)
	{
		counter += dayCountInMonths[i];
	}
/* date.dies is treated as an offset, regardless of date legality */
	counter += date.dies + (int)(isLeapYear && date.mensis > 2);

	return counter;
}
