// (a) Write a program that reads a message, then checks whether it’s a
// palindrome (the letters in the message are the same from left to right as
// from right to left):
//
// Enter a message: He lived as a devil, eh?
// Palindrome
//
// Enter a message: Madam, I am Adam.
// Not a palindrome
//
// Ignore all characters that aren’t letters. Use integer variables to keep
// track of positions in the array.
//
// (b) Revise the program to use pointers instead of integers to keep track of
// positions in the array.

#include <ctype.h>
#include <stdio.h>

#define SIZE 100

int main(void)
{
	printf("Enter a message: ");

	char c;
	char message[SIZE];
	char *p = &message[0];

	while (p < &message[SIZE] && (c = getchar()) != '\n')
		if (isalpha(c))
			*p++ = tolower(c);

	char *q = &message[0];

	while (p > q) {
		if (*q++ != *--p) {
			printf("Not a palindrome\n");
			return 0;
		}
	}

	printf("Palindrome\n");

	return 0;
}
