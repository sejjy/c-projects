// Modify Programming Project 6 from Chapter 3 so that the user may add,
// subtract, multiply, or divide two fractions (by entering either +, -, *, or /
// between the fractions).

/* Adds two fractions */

#include <stdio.h>

int main(void)
{
	int num1, denom1, num2, denom2, result_num, result_denom;

	// printf("Enter two fractions separated by a plus sign: ");
	// scanf("%d/%d+%d/%d", &num1, &denom1, &num2, &denom2);
	//
	// result_num = num1 * denom2 + num2 * denom1;
	// result_denom = denom1 * denom2;

	char operator;

	printf("Enter two fractions separated by an operator: ");
	scanf("%d/%d %c %d/%d", &num1, &denom1, &operator, &num2, &denom2);

	printf("The ");

	switch (operator) {
		case '+':
			result_num = num1 * denom2 + num2 * denom1;
			result_denom = denom1 * denom2;
			printf("sum");
			break;
		case '-':
			result_num = num1 * denom2 - num2 * denom1;
			result_denom = denom1 * denom2;
			printf("difference");
			break;
		case '*':
			result_num = num1 * num2;
			result_denom = denom1 * denom2;
			printf("product");
			break;
		case '/':
			result_num = num1 * denom2;
			result_denom = denom1 * num2;
			printf("quotient");
			break;
		default:
			printf("input is invalid\n");
			return 1;
	}

	printf(" is %d/%d\n", result_num, result_denom);

	return 0;
}
