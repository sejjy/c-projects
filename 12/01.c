// (a) Write a program that reads a message, then prints the reversal of the
// message:
//
// Enter a message: Don't get mad, get even.
// Reversal is: .neve teg ,dam teg t'noD
//
// Hint: Read the message one character at a time (using getchar) and store the
// characters in an array. Stop reading when the array is full or the character
// read is '\n'.
//
// (b) Revise the program to use a pointer instead of an integer to keep track
// of the current position in the array.

#include <stdio.h>

#define SIZE 100

int main(void)
{
	printf("Enter a message: ");

	char c;
	char message[SIZE];
	char *p = &message[0];

	while (p < &message[SIZE] && (c = getchar()) != '\n')
		*p++ = c;

	printf("Reversal is: ");

	while (p > &message[0])
		printf("%c", *--p);

	printf("\n");

	return 0;
}
