// Modify the repdigit.c program of Section 8.1 so that it shows which digits
// (if any) were repeated:
//
// Enter a number: 939577
// Repeated digit(s): 7 9

/* Checks numbers for repeated digits */

#include <stdbool.h> /* C99 only */
#include <stdio.h>

int main(void)
{
	long n;

	printf("Enter a number: ");
	scanf("%ld", &n);

	int digit;
	bool digit_seen[10] = {false};

	printf("Repeated digit(s):");
	while (n > 0) {
		digit = n % 10;

		if (digit_seen[digit]) {
			printf(" %d", digit);
		}

		digit_seen[digit] = true;
		n /= 10;
	}
	printf("\n");

	return 0;
}
