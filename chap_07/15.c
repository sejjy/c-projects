// Write a program that computes the factorial of a positive integer:
//
// Enter a positive integer: 6
// Factorial of 6: 720
//
// (a) Use a short variable to store the value of the factorial. What is the
//     largest value of n for which the program correctly prints the factorial
//     of n?
// (b) Repeat part (a), using an int variable instead.
// (c) Repeat part (a), using a long variable instead.
// (d) Repeat part (a), using a long long variable instead (if your compiler
//     supports the long long type).
// (e) Repeat part (a), using a float variable instead.
// (f) Repeat part (a), using a double variable instead.
// (g) Repeat part (a), using a long double variable instead.
//
// In cases (e)–(g), the program will display a close approximation of the
// factorial, not necessarily the exact value.

#include <stdio.h>

int main(void)
{
	int n;

	printf("Enter a positive integer: ");
	scanf("%d", &n);

	long double factorial = 1.0L;

	for (int i = n; i > 1; i--) {
		factorial *= i;
	}

	printf("Factorial of %d: %.0Lf\n", n, factorial);

	return 0;
}

// (a) short:          7
// (b) int:           12
// (c) long:          20
// (d) long long:     20
// (e) float:         34
// (f) double:       170
// (g) long double: 1754
