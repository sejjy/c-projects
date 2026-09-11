// Modify Programming Project 8 from Chapter 5 so that the departure times are
// stored in an array and the arrival times are stored in a second array. (The
// times are integers, representing the number of minutes since midnight.) The
// program will use a loop to search the array of departure times for the one
// closest to the time entered by the user.

#include <stdio.h>

int main(void)
{
	int hours, minutes;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hours, &minutes);

	int time_in_mins = (hours * 60) + minutes;

	int d[8] = {480, 583, 679, 767, 840, 945, 1140, 1305};
	int a[8] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

	int d_hour, d_minute;
	char d_char;

	int a_hour, a_minute;
	char a_char;

	int i;

	for (i = 0; i < 8 - 1; i++) {
		if (time_in_mins <= (d[i] + d[i + 1]) / 2) {
			break;
		}
	}

	d_hour   = d[i] / 60;
	d_minute = d[i] % 60;

	a_hour   = a[i] / 60;
	a_minute = a[i] % 60;

	d_char = (d_hour >= 12) ? 'p' : 'a';
	a_char = (a_hour >= 12) ? 'p' : 'a';

	if (d_hour == 0) d_hour  = 12;
	if (d_hour > 12) d_hour -= 12;

	if (a_hour == 0) a_hour  = 12;
	if (a_hour > 12) a_hour -= 12;

	printf("Closest departure time is %d:%02d %c.m., "
			"arriving at %d:%02d %c.m.\n",
			d_hour, d_minute, d_char,
			a_hour, a_minute, a_char);

	return 0;
}
