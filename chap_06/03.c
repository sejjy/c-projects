// Write a program that asks the user to enter a fraction, then reduces the
// fraction to lowest terms:
//
// Enter a fraction: 6/12
// In lowest terms: 1/2
//
// Hint: To reduce a fraction to lowest terms, first compute the GCD of the
// numerator and denominator. Then divide both the numerator and denominator by
// the GCD.

#include <stdio.h>

int main(void)
{
	int numerator, denominator;

	printf("Enter a fraction: ");
	scanf("%d/%d", &numerator, &denominator);


	if (denominator == 0) {
		printf("Error: division by zero\n");
		return 1;
	}

	int n = numerator, d = denominator, rem;

	while (d != 0) {
		rem = n % d;
		n = d;
		d = rem;
	}

	numerator /= n;
	denominator /= n;

	printf("In lowest terms: %d/%d\n", numerator, denominator);

	return 0;
}
