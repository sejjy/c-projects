// Extend the program in Programming Project 1 to handle three-digit numbers.

#include <stdio.h>

int main(void)
{
	int num, digit1, digit2, digit3;

	printf("Enter a three-digit number: ");
	scanf("%d", &num);

	digit1 = num / 100;
	digit2 = (num / 10) % 10;
	digit3 = num % 10;

	printf("The reversal is: %d%d%d\n", digit3, digit2, digit1);

	return 0;
}
