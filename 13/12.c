// Modify Programming Project 14 from Chapter 8 so that it stores the words in a
// two-dimensional char array as it reads the sentence, with each row of the
// array storing a single word. Assume that the sentence contains no more than
// 30 words and no word is more than 20 characters long. Be sure to store a null
// character at the end of each word so that it can be treated as a string.

#include <stdio.h>

#define MAX_WORDS 30
#define MAX_CHARS 20

int main(void)
{
	printf("Enter a sentence: ");

	char c;
	char punct = 0;
	char sentence[MAX_WORDS][MAX_CHARS];
	int i = 0, j = 0;

	while (i < MAX_WORDS && (c = getchar()) != '\n') {
		if (c == '.' || c == '?' || c == '!')
		{
			punct = c;
			sentence[i][j] = '\0';	
			break;
		}
		if (c == ' ')
		{
			sentence[i++][j] = '\0';	
			j = 0;
			continue;
		}
		if (j < MAX_WORDS)
			sentence[i][j++] = c;
	}

	printf("Reversal of sentence: ");

	while (i > 0)
		printf("%s ", sentence[i--]);
	printf("%s%c\n", sentence[i], punct);

	return 0;
}
