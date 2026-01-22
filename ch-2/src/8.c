// Write a program that calculates the remaining balance on a loan after the first, second, and
// third monthly payments:
// Enter amount of loan: 20000.00
// Enter interest rate: 6.0
// Enter monthly payment: 386.66
// Balance remaining after first payment: $19713.34
// Balance remaining after second payment: $19425.25
// Balance remaining after third payment: $19135.71
// Display each balance with two digits after the decimal point. Hint: Each month, the balance
// is decreased by the amount of the payment, but increased by the balance times the monthly
// interest rate. To find the monthly interest rate, convert the interest rate entered by the user to
// a percentage and divide it by 12.

#include <stdio.h>

int main(void)
{
	float loan, interest_rate, monthly_payment;

	printf("Enter amount of loan: ");
	scanf("%f", &loan);
	printf("Enter interest rate: ");
	scanf("%f", &interest_rate);
	printf("Enter monthly payment: ");
	scanf("%f", &monthly_payment);

	// loan = 20000.0f;
	// interest_rate = 6.0f;
	// monthly_payment = 386.66f;

	loan = (loan - monthly_payment) + (loan * (0.06 / 12));
	printf("\nBalance remaining after first payment: %.2f\n", loan);

	loan = (loan - monthly_payment) + (loan * (0.06 / 12));
	printf("Balance remaining after second payment: %.2f\n", loan);

	loan = (loan - monthly_payment) + (loan * (0.06 / 12));
	printf("Balance remaining after third payment: %.2f\n", loan);

	return 0;
}
