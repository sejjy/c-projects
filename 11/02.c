// Modify Programming Project 8 from Chapter 5 so that it includes the following
// function:
//
// void find_closest_flight(int desired_time,
//                          int *departure_time,
//                          int *arrival_time);
//
// This function will find the flight whose departure time is closest to
// desired_time (expressed in minutes since midnight). It will store the
// departure and arrival times of this flight (also expressed in minutes since
// midnight) in the variables pointed to by departure_time and arrival_time,
// respectively.

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
	// minutes since midnight
	int d[8] = {480, 583, 679, 767, 840,  945, 1140, 1305};
	int a[8] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

	for (int i = 0; i < 8 - 1; i++) {
		if (desired_time <= (d[i] + d[i + 1]) / 2) {
			*departure_time = d[i];
			*arrival_time   = a[i];
			return;
		}
	}
}
