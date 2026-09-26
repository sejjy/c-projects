// Modify Programming Project 15 from Chapter 8 so that it includes the
// following function:
//
// void encrypt(char *message, int shift);
//
// The function expects message to point to a string containing the message to
// be encrypted; shift represents the amount by which each letter in the message
// is to be shifted.

#include <stdio.h>

#define MSG_LEN   80
#define ALPHA_LEN 26

void encrypt(char *message, int shift);

int main(void)
{
	char message[MSG_LEN];

	printf("Enter message to be encrypted: ");
	fgets(message, sizeof(message), stdin);

	int shift;

	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift);

	printf("Encrypted message: ");
	encrypt(message, shift);

	return 0;
}

void encrypt(char *message, int shift)
{
	while (*message) {
		if (*message >= 'A' && *message <= 'Z')
		{
			printf("%c", (*message - 'A' + shift) % ALPHA_LEN + 'A');
		}
		else if (*message >= 'a' && *message <= 'z')
		{
			printf("%c", (*message - 'a' + shift) % ALPHA_LEN + 'a');
		}
		else
		{
			printf("%c", *message);
		}

		message++;
	}
}
