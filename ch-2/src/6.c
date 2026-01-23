// Modify the program of Programming Project 5 so that the polynomial is evaluated using the
// following formula:
//
// ((((3x + 2)x – 5)x – 1)x + 7)x – 6
//
// Note that the modified program performs fewer multiplications. This technique for evaluat-
// ing polynomials is known as Horner’s Rule.

#include <stdio.h>

int main(void)
{
	printf("Expression\n");
	printf("3x⁵ + 2x⁴ – 5x³ – x² + 7x – 6\n");

	float value;

	printf("\nEnter a value: ");
	scanf("%f", &value);

	printf("\nSolution\n");
	printf("= (((((3)(%.2f) + 2)%.2f – 5)%.2f – 1)%.2f + 7)%.2f – 6\n",
	       value, value, value, value, value);

	float answer =
		((((3 * value + 2) * value - 5) * value - 1) * value + 7) * value - 6;

	printf("= %.2f\n", answer);

	return 0;
}
