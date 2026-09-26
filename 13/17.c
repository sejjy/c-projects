// Modify Programming Project 2 from Chapter 12 so that it includes the
// following function:
//
// bool is_palindrome(const char *message);
//
// The function returns true if the string pointed to by message is a
// palindrome.

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MSG_LEN 100

bool is_palindrome(const char *message);

int main(void)
{
	printf("Enter a message: ");

	char message[MSG_LEN], *p = message, c;

	while (p < message + MSG_LEN && (c = getchar()) != '\n')
		if (isalpha(c))
			*p++ = tolower(c);

	if (is_palindrome(message))
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");

	return 0;
}

bool is_palindrome(const char *message)
{
	const char *p = message, *q = message;

	while (*q)
		q++;
	q--;

	while (p < q)
		if (*p++ != *q--)
			return false;

	return true;
}
