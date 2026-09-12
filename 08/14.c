// Write a program that reverses the words in a sentence:
//
// Enter a sentence: you can cage a swallow can't you?
// Reversal of sentence: you can't swallow a cage can you?
//
// Hint: Use a loop to read the characters one by one and store them in a
// one-dimensional char array. Have the loop stop at a period, question mark, or
// exclamation point (the “terminating character”), which is saved in a separate
// char variable. Then use a second loop to search backward through the array
// for the beginning of the last word. Print the last word, then search backward
// for the next-to-last word. Repeat until the beginning of the array is
// reached. Finally, print the terminating character.

#include <stdio.h>

#define SIZE 64

int main(void)
{
	printf("Enter a sentence: ");

	char c;
	char input[SIZE] = {0};
	int i = 0;
	char punct = 0;

	while ((c = getchar()) != '\n') {
		if (c == '.' || c == '?' || c == '!') {
			punct = c;
			break;
		}

		input[i++] = c;
	}

	printf("Reversal of sentence: ");

	int j;
	int start;
	// you can cage a swallow can't you?
	//                                ^
	int end = i - 1;

	for (j = end; j >= 0; j--) {
		if (j == 0 || input[j - 1] == ' ') {
			// you can cage a swallow can't you?
			//                              ^
			start = j;

			// you can cage a swallow can't you?
			//                              ^^^
			while (start <= end) {
				printf("%c", input[start++]);
			}

			if (j != 0) {
				printf(" ");
			}

			// you can cage a swallow can't you?
			//                            ^
			end = j - 2;
		}
	}

	printf("%c\n", punct);

	return 0;
}
