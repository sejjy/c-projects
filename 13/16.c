// Modify Programming Project 1 from Chapter 12 so that it includes the
// following function:
//
// void reverse(char *message);
//
// The function reverses the string pointed to by message. Hint: Use two
// pointers, one initially pointing to the first character of the string and the
// other initially pointing to the last character. Have the function reverse
// these characters and then move the pointers toward each other, repeating the
// process until the pointers meet.

#include <stdio.h>

#define MSG_LEN 100

void reverse(char *message);

int main(void)
{
	char message[MSG_LEN];

	printf("Enter a message: ");
	fgets(message, sizeof(message), stdin);

	reverse(message);
	printf("Reversal is: %s", message);

	return 0;
}

void reverse(char *message)
{
	char *p = message;

	while (*message != '\n')
		message++;
	message--;

	char *q = message;
	char temp;

	while (p < q) {
		temp = *p;
		*p++ = *q;
		*q-- = temp;
	}
}
