// Modify the repdigit.c program of Section 8.1 so that the user can enter more
// than one number to be tested for repeated digits. The program should
// terminate when the user enters a number that’s less than or equal to 0.

/* Checks numbers for repeated digits */

#include <stdio.h>

#define DIGITS 10

int main(void)
{
	long number, n;
	int digit, occur[DIGITS], i;

	do {
		printf("Enter a number: ");
		scanf("%ld", &number);

		n = number;
		while (n > 0) {
			digit = n % 10;
			occur[digit]++;
			n /= 10;
		}

		printf("Digit:      ");
		for (i = 0; i < DIGITS; i++) {
			printf("%3d", i);
		}

		printf("\nOccurrences:");
		for (i = 0; i < DIGITS; i++) {
			printf("%3d", occur[i]);
			occur[i] = 0;
		}
		printf("\n");
	} while (number > 0);

	return 0;
}
