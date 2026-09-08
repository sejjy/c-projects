// Modify the program of Programming Project 5 so that the polynomial is
// evaluated using the following formula:
//
// ((((3x + 2)x – 5)x – 1)x + 7)x – 6
//
// Note that the modified program performs fewer multiplications. This technique
// for evaluating polynomials is known as Horner’s Rule.

#include <stdio.h>

int main(void)
{
	printf("Expression\n");
	printf("3x⁵ + 2x⁴ – 5x³ – x² + 7x – 6\n");

	float x;

	printf("\nEnter a value: ");
	scanf("%f", &x);

	printf("\nSolution\n");
	printf("= (((((3)(%.2f) + 2)%.2f – 5)%.2f – 1)%.2f + 7)%.2f – 6\n",
	       x, x, x, x, x);

	float answer = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;

	printf("= %.2f\n", answer);

	return 0;
}
