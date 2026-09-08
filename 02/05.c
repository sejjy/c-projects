// Write a program that asks the user to enter a value for x and then displays
// the value of the following polynomial:
//
// 3x⁵ + 2x⁴ – 5x³ – x² + 7x – 6
//
// Hint: C doesn’t have an exponentiation operator, so you’ll need to multiply x
// by itself repeatedly in order to compute the powers of x. (For example, x *
// x * x is x cubed.)

#include <stdio.h>

int main(void)
{
	printf("Expression\n");
	printf("3x⁵ + 2x⁴ – 5x³ – x² + 7x – 6\n");

	float x;

	printf("\nEnter a value: ");
	scanf("%f", &x);

	printf("\nSolution\n");
	printf("= 3(%.2f⁵) + 2(%.2f⁴) − 5(%.2f³) − %.2f² + (7)(%.2f) − 6\n",
	       x, x, x, x, x);

	float answer = (3 * (x * x * x * x * x)) + (2 * (x * x * x * x)) -
	               (5 * (x * x * x)) - (x * x) + (7 * x) - 6;

	printf("= %.2f\n", answer);

	return 0;
}
