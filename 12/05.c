// Modify Programming Project 14 from Chapter 8 so that it uses a pointer
// instead of an integer to keep track of the current position in the array that
// contains the sentence.

#include <stdio.h>

#define SIZE 64

int main(void)
{
	printf("Enter a sentence: ");

	char c;
	char input[SIZE] = {0};
	char *p = input;
	char punct = 0;

	while ((c = getchar()) != '\n') {
		if (c == '.' || c == '?' || c == '!') {
			punct = c;
			break;
		}

		*p++ = c;
	}

	printf("Reversal of sentence: ");

	char *q;
	char *start;
	// you can cage a swallow can't you?
	//                                ^
	char *end = p - 1;

	for (q = end; q >= input; q--) {
		if (q == input || *(q - 1) == ' ') {
			// you can cage a swallow can't you?
			//                              ^
			start = q;

			// you can cage a swallow can't you?
			//                              ^^^
			while (start <= end) {
				printf("%c", *start++);
			}

			if (q != input) {
				printf(" ");
			}

			// you can cage a swallow can't you?
			//                            ^
			end = q - 2;
		}
	}

	printf("%c\n", punct);

	return 0;
}
