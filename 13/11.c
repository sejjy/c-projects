// Modify Programming Project 13 from Chapter 7 so that it includes the
// following function:
//
// double compute_average_word_length(const char *sentence);
//
// The function returns the average length of the words in the string pointed to
// by sentence.

#include <stdio.h>

#define SENT_LEN 100

double compute_average_word_length(const char *sentence);

int main(void)
{
	char sentence[SENT_LEN + 1];

	printf("Enter a sentence: ");
	fgets(sentence, sizeof(sentence), stdin);

	printf("Average word length: %.1lf\n",
			compute_average_word_length(sentence));

	return 0;
}

double compute_average_word_length(const char *sentence)
{
	while (*sentence == ' ')
		sentence++;

	int words = 1, letters = 0;

	while (*sentence != '\n') {
		if (*sentence++ == ' ')
			words++;
		else
			letters++;
	}

	return (double) letters / words;
}
