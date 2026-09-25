// Write a program that finds the “smallest” and “largest” in a series of words.
// After the user enters the words, the program will determine which words would
// come first and last if the words were listed in dictionary order. The program
// must stop accepting input when the user enters a four-letter word. Assume
// that no word is more than 20 letters long. An interactive session with the
// program might look like this:
//
// Enter word: dog
// Enter word: zebra
// Enter word: rabbit
// Enter word: catfish
// Enter word: walrus
// Enter word: cat
// Enter word: fish
//
// Smallest word: cat
// Largest word: zebra
//
// Hint: Use two strings named smallest_word and largest_word to keep track of
// the “smallest” and “largest” words entered so far. Each time the user enters
// a new word, use strcmp to compare it with smallest_word; if the new word is
// “smaller,” use strcpy to save it in smallest_word. Do a similar comparison
// with largest_word. Use strlen to determine when the user has entered a
// four-letter word.

#include <stdio.h>
#include <string.h>

#define WORD_LEN 20

char word[WORD_LEN + 1];

void read_word(void);

int main(void)
{
	char smallest_word[WORD_LEN + 1];
	char largest_word[WORD_LEN + 1];

	read_word();

	strcpy(smallest_word, word);
	strcpy(largest_word, word);

	while (strlen(word) != 4) {
		read_word();

		if (strcmp(word, smallest_word) < 0)
			strcpy(smallest_word, word);
		else if (strcmp(word, largest_word) > 0)
			strcpy(largest_word, word);
	}

	printf("\nSmallest word: %s\n", smallest_word);
	printf("Largest word: %s\n", largest_word);

	return 0;
}

void read_word(void)
{
	printf("Enter word: ");
	scanf("%20s", word);
}
