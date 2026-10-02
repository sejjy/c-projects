// Modify Programming Project 8 from Chapter 5 so that the times are stored in a
// single array. The elements of the array will be structures, each containing a
// departure time and the corresponding arrival time. (Each time will be an
// integer, representing the number of minutes since midnight.) The program will
// use a loop to search the array for the departure time closest to the time
// entered by the user.

#include <stdio.h>

void find_closest_flight(int desired_time,
                         int *departure_time,
                         int *arrival_time);

int main(void)
{
	int hour, minute;

	printf("Enter a 24-hour time: ");		
	scanf("%d:%d", &hour, &minute);

	int desired_time = (hour * 60) + minute;
	int departure_time;
	int arrival_time;

	find_closest_flight(desired_time, &departure_time, &arrival_time);

	int d_hour = departure_time / 60;
	int a_hour = arrival_time   / 60;

	int d_minute = departure_time % 60;
	int a_minute = arrival_time   % 60;

	char d_char = (d_hour >= 12) ? 'p' : 'a';
	char a_char = (a_hour >= 12) ? 'p' : 'a';

	if (d_hour == 0) d_hour = 12;
	if (a_hour == 0) a_hour = 12;

	if (d_hour > 12) d_hour -= 12;
	if (a_hour > 12) a_hour -= 12;

	printf("Closest departure time is %.2d:%.2d %c.m., "
			"arriving at %.2d:%.2d %c.m.\n",
			d_hour, d_minute, d_char,
			a_hour, a_minute, a_char);

	return 0;
}

void find_closest_flight(int desired_time,
                         int *departure_time,
                         int *arrival_time)
{
	typedef struct {
		int departure_time;
		int arrival_time;
	} Time;

	const Time times[] = {
		{ 480,  616},
		{ 583,  712},
		{ 679,  811},
		{ 767,  900},
		{ 840,  968},
		{ 945, 1075},
		{1140, 1280},
		{1305, 1438},
	};

	for (int i = 0; i < 8 - 1; i++) {
		if (desired_time <= (times[i].departure_time +
					times[i+1].departure_time) / 2)
		{
			*departure_time = times[i].departure_time;
			*arrival_time   = times[i].arrival_time;
			return;
		}
	}
}
