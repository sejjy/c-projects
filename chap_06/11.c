// The value of the mathematical constant e can be expressed as an infinite
// series:
//
// e = 1 + 1/1! + 1/2! + 1/3! + …
//
// Write a program that approximates e by computing the value of
//
// 1 + 1/1! + 1/2! + 1/3! + … + 1/n!
//
// where n is an integer entered by the user.

#include <stdio.h>

int main(void)
{
	int n;

	printf("Enter an integer: ");
	scanf("%d", &n);

	printf("\ne = 1");

	int factorial = 1;
	float e = 1.0f;

	for (int i = 1; i <= n; i++) {
		printf(" + 1/%d!", i);

		factorial *= i;
		e += 1.0f / factorial;
	}

	printf("\ne = %f\n", e);
	// printf("\n%d! = %d\n", n, factorial);

	return 0;
}
