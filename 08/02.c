// Modify the repdigit.c program of Section 8.1 so that it prints a table
// showing how many times each digit appears in the number:
//
// Enter a number: 41271092
// Digit:        0  1  2  3  4  5  6  7  8  9
// Occurrences:  1  2  2  0  1  0  0  1  0  1

/* Checks numbers for repeated digits */

#include <stdio.h>

#define DIGITS 10

int main(void)
{
	long number;

	printf("Enter a number: ");
	scanf("%ld", &number);

	int digit, occur[DIGITS];

	while (number > 0) {
		digit = number % 10;
		occur[digit]++;
		number /= 10;
	}

	printf("Digit:      ");
	for (int i = 0; i < DIGITS; i++) {
		printf("%3d", i);
	}

	printf("\nOccurrences:");
	for (int i = 0; i < DIGITS; i++) {
		printf("%3d", occur[i]);
	}
	printf("\n");

	return 0;
}
