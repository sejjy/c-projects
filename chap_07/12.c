// Write a program that evaluates an expression:
//
// Enter an expression: 1+2.5*3
// Value of expression: 10.5
//
// The operands in the expression are floating-point numbers; the operators are
// +, -, *, and /. The expression is evaluated from left to right (no operator
// takes precedence over any other operator).

#include <stdio.h>

int main(void)
{
	float value = 0.0f;

	printf("Enter an expression: ");
	scanf("%f", &value);

	char ch;
	float next = 0.0f;

	while ((ch = getchar()) != '\n') {
		switch (ch) {
			case '+':
				scanf("%f", &next);
				value += next;
				break;
			case '-':
				scanf("%f", &next);
				value -= next;
				break;
			case '*':
				scanf("%f", &next);
				value *= next;
				break;
			case '/':
				scanf("%f", &next);
				value /= next;
				break;
			default:
				break;
		}
	}

	printf("Value of expression: %f\n", value);

	return 0;
}
