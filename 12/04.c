// Simplify Programming Project 2(b) by taking advantage of the fact that an
// array name can be used as a pointer.

#include <ctype.h>
#include <stdio.h>

#define SIZE 100

int main(void)
{
	printf("Enter a message: ");

	char c;
	char message[SIZE];
	char *p = message;

	while (p < message + SIZE && (c = getchar()) != '\n')
		if (isalpha(c))
			*p++ = tolower(c);

	char *q = message;

	while (p > q) {
		if (*q++ != *--p) {
			printf("Not a palindrome\n");
			return 0;
		}
	}

	printf("Palindrome\n");

	return 0;
}
