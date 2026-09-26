// Modify Programming Project 11 from Chapter 5 so that it uses arrays
// containing pointers to strings instead of switch statements. For example,
// instead of using a switch statement to print the word for the first digit,
// use the digit as an index into an array that contains the strings "twenty",
// "thirty", and so forth.

#include <stdio.h>

int main(void)
{
	char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen",
	                 "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"},
	      *tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy",
	                 "eighty", "ninety"},
	      *ones[] = {"one", "two", "three", "four", "five", "six", "seven",
	                 "eight", "nine"};
	int number;

	printf("Enter a two-digit number: ");		
	scanf("%d", &number);

	int n1 = number / 10;
	int n2 = number % 10;

	if (number < 10 || number > 99)
	{
		printf("Invalid two-digit number\n");
		return 1;
	}
	else if (number >= 10 && number <= 19)
		printf("%s\n", teens[n2]);
	else
	{
		printf("%s", tens[n1 - 2]);
		if (n2 != 0)
			printf("-%s", ones[n2 - 1]);
		printf("\n");
	}

	return 0;
}
