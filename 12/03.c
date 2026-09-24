// Simplify Programming Project 1(b) by taking advantage of the fact that an
// array name can be used as a pointer.

#include <stdio.h>

#define SIZE 100

int main(void)
{
	printf("Enter a message: ");

	char c;
	char message[SIZE];
	char *p = message;

	while (p < message + SIZE && (c = getchar()) != '\n')
		*p++ = c;

	printf("Reversal is: ");

	while (p > message)
		printf("%c", *--p);

	printf("\n");

	return 0;
}
