// Modify Programming Project 16 from Chapter 8 so that it includes the
// following function:
//
// bool are_anagrams(const char *word1, const char *word2);
//
// The function returns true if the strings pointed to by word1 and word2 are
// anagrams.

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define ALPHA_LEN 26
#define WORD_LEN  20

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
	char word1[WORD_LEN];

	printf("Enter first word: ");
	fgets(word1, sizeof(word1), stdin);

	char word2[WORD_LEN];

	printf("Enter second word: ");
	fgets(word2, sizeof(word2), stdin);

	printf("The words are ");
	if (!are_anagrams(word1, word2))
		printf("not ");
	printf("anagrams.\n");

	return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
	int input[ALPHA_LEN] = {0};

	while(*word1) {
		if (isalpha(*word1))
			input[tolower(*word1) - 'a']++;
		word1++;
	}

	while(*word2) {
		if (isalpha(*word2))
			input[tolower(*word2) - 'a']--;
		word2++;
	}

	int *p = input;
	while (p < input + ALPHA_LEN)
		if (*p++ != 0)
			return false;

	return true;
}
