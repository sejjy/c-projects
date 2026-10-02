// Modify Programming Project 9 from Chapter 5 so that each date entered by the
// user is stored in a date structure (see Exercise 5). Incorporate the
// compare_dates function of Exercise 5 into your program.

#include <stdio.h>

struct date {
	int month;
	int day;
	int year;
};

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);

int main(void)
{
	struct date d1, d2;

	printf("Enter first date (mm/dd/yy): ");
	scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);

	printf("Enter second date (mm/dd/yy): ");
	scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);

	switch (compare_dates(d1, d2)) {
		case -1:
			printf("%d/%d/%d is earlier than %d/%d/%d\n",
					d1.month, d1.day, d1.year,
					d2.month, d2.day, d2.year);
			break;
		case  1:
			printf("%d/%d/%d is later than %d/%d/%d\n",
					d1.month, d1.day, d1.year,
					d2.month, d2.day, d2.year);
			break;
		default:
			printf("%d/%d/%d and %d/%d/%d are the same\n",
					d1.month, d1.day, d1.year,
					d2.month, d2.day, d2.year);
			break;
	}

	return 0;
}

// Returns the day of the year (an integer between 1 and 366) that corresponds
// to the date d.
int day_of_year(struct date d)
{
	const int days_of_month[12] = {
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};

	int day = 0;

	for (int i = 1; i < d.month; i++)
		day += days_of_month[i - 1];

	if (d.month > 2 &&
			(d.year % 400 == 0 ||
			(d.year %   4 == 0 && d.year % 100 != 0)))
		day++;

	return day + d.day;
}

// Returns –1 if d1 is an earlier date than d2, +1 if d1 is a later date than
// d2, and 0 if d1 and d2 are the same.
int compare_dates(struct date d1, struct date d2)
{
	if (d1.year < d2.year) return -1;
	if (d1.year > d2.year) return  1;

	if (day_of_year(d1) < day_of_year(d2)) return -1;
	if (day_of_year(d1) > day_of_year(d2)) return  1;

	return 0;
}
