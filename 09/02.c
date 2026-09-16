// Modify Programming Project 5 from Chapter 5 so that it uses a function to
// compute the amount of income tax. When passed an amount of taxable income,
// the function will return the tax due.

#include <stdio.h>

float compute_income_tax(float income);

int main(void)
{
	float income, tax;

	printf("Enter the amount of taxable income: ");	
	scanf("%f", &income);

	tax = compute_income_tax(income);

	printf("Tax due: $%.2f\n", tax);

	return 0;
}

float compute_income_tax(float income)
{
	float tax;

	if (income <= 750) {
		tax = income * 0.01f;
	}
	else if (income <= 2250) {
		tax = 7.50f + ((income - 750) * 0.02f);
	}
	else if (income <= 3750) {
		tax = 37.50f + ((income - 2250) * 0.03f);
	}
	else if (income <= 5250) {
		tax = 82.50f + ((income - 3750) * 0.04f);
	}
	else if (income <= 7000) {
		tax = 142.50f + ((income - 5250) * 0.05f);
	}
	else {
		tax = 230.00f + ((income - 7000) * 0.06f);
	}

	return tax;
}
