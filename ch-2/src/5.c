// Write a program that asks the user to enter a value for x and then displays the value of the
// following polynomial:
// 3x⁵ + 2x⁴ – 5x³ – x² + 7x – 6
// 3x^5 + 2x^4 – 5x^3 – x^2 + 7x – 6
// Hint: C doesn’t have an exponentiation operator, so you’ll need to multiply x by itself
// repeatedly in order to compute the powers of x. (For example, x * x * x is x cubed.)

#include <stdio.h>

float second(float x) { return x * x; }
float third(float x)  { return x * x * x; }
float fourth(float x) { return x * x * x * x; }
float fifth(float x)  { return x * x * x * x * x; }

int main(void)
{
	printf("Expression\n");
	printf("3x⁵ + 2x⁴ – 5x³ – x² + 7x – 6\n");

	float value;

	printf("\nEnter a value: ");
	scanf("%f", &value);

	printf("\nSolution\n");
	printf("= 3(%.2f⁵) + 2(%.2f⁴) − 5(%.2f³) − %.2f² + (7)(%.2f) − 6\n",
	       value, value, value, value, value);

	float answer = (3 * fifth(value)) + (2 * fourth(value)) -
	               (5 * third(value)) - second(value) + (7 * value) - 6;

	printf("= %.2f\n", answer);

	return 0;
}
