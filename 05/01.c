// Write a program that calculates how many digits a number contains:
//
// Enter a number: 374
// The number 374 has 3 digits
//
// You may assume that the number has no more than four digits. Hint: Use if
// statements to test the number. For example, if the number is between 0 and 9,
// it has one digit. If the num- ber is between 10 and 99, it has two digits.

#include <stdio.h>

int main(void)
{
	int num;

	printf("Enter a number: ");
	scanf("%d", &num);

	if (num < 0 || num > 9999) {
		printf("Number must be 0-9999\n");
	} else {
		printf("The number %d has ", num);

		if (num >= 0 && num <= 9)
			printf("1 digit\n");
		else if (num >= 10 && num <= 99)
			printf("2 digits\n");
		else if (num >= 100 && num <= 999)
			printf("3 digits\n");
		else
			printf("4 digits\n");
	}

	return 0;
}
