// Improve the remind.c program of Section 13.5 in the following ways:
//
// (a) Have the program print an error message and ignore a reminder if the
//     corresponding day is negative or larger than 31. Hint: Use the continue
//     statement.
// (b) Allow the user to enter a day, a 24-hour time, and a reminder. The
//     printed reminder list should be sorted first by day, then by time. (The
//     original program allows the user to enter a time, but it’s treated as
//     part of the reminder.)
// (c) Have the program print a one-year reminder list. Require the user to
//     enter days in the form month/day.

/* Prints a one-month reminder list */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50 /* maximum number of reminders */
#define MSG_LEN 60 /* max length of reminder message */

int read_line(char str[], int n);
void discard_line(void);

int main(void)
{
	char reminders[MAX_REMIND][MSG_LEN+3];
	char day_str[30], msg_str[MSG_LEN+1];
	int month, day, hours, minutes, i, j, num_remind = 0;

	for (;;) {
		if (num_remind == MAX_REMIND) {
			printf("-- No space left --\n");
			break;
		}

		printf("Enter reminder (mm/dd hh:mm message): ");
		scanf("%d/%d", &month, &day);

		if (month == 0 || day == 0)
			break;
		if (month < 1 || month > 12) {
			printf("-- Month out of range (0-12) --\n");
			discard_line();
			continue;
		}
		if (day < 1 || day > 31) {
			printf("-- Day out of range (0-31) --\n");
			discard_line();
			continue;
		}

		scanf("%d:%d", &hours, &minutes);

		if (hours < 0 || hours > 23) {
			printf("-- Hour out of range (00-23) --\n");
			discard_line();
			continue;
		}
		if (minutes < 0 || minutes > 59) {
			printf("-- Minute out of range (00-59) --\n");
			discard_line();
			continue;
		}

		sprintf(day_str, "%02d/%02d %02d:%02d", month, day, hours, minutes);
		read_line(msg_str, MSG_LEN);

		for (i = 0; i < num_remind; i++)
			if (strcmp(day_str, reminders[i]) < 0)
				break;
		for (j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j-1]);

		strcpy(reminders[i], day_str);
		strcat(reminders[i], msg_str);

		num_remind++;
	}

	printf("\nMonth Day Time  Reminder\n");
	for (i = 0; i < num_remind; i++)
		printf(" %s\n", reminders[i]);

	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}

void discard_line(void)
{
	while (getchar() != '\n')
		;
}
