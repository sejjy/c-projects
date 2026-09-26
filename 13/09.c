// Modify Programming Project 10 from Chapter 7 so that it includes the
// following function:
//
// int compute_vowel_count(const char *sentence);
//
// The function returns the number of vowels in the string pointed to by the
// sentence parameter.

#include <ctype.h>
#include <stdio.h>

#define SENT_LEN 100

int compute_vowel_count(const char *sentence);

int main(void)
{
	char sentence[SENT_LEN + 1];

	printf("Enter a sentence: ");
	fgets(sentence, sizeof(sentence), stdin);

	printf("Your sentence contains %d vowels\n", compute_vowel_count(sentence));

	return 0;
}

int compute_vowel_count(const char *sentence)
{
	int count = 0;

	while (*sentence) {
		switch (toupper((unsigned char)*sentence++)) {
			case 'A': case 'E': case 'I': case 'O': case 'U':
				count += 1;
				break;
		}
	}
		
	return count;
}
