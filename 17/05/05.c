// Write a program that sorts a series of words entered by the user:
//
// Enter word: foo
// Enter word: bar
// Enter word: baz
// Enter word: quux
// Enter word:
//
// In sorted order: bar baz foo quux
//
// Assume that each word is no more than 20 characters long. Stop reading when
// the user enters an empty word (i.e., presses Enter without entering a word).
// Store each word in a dynamically allocated string, using an array of pointers
// to keep track of the strings, as in the remind2.c program (Section 17.2).
// After all words have been read, sort the array (using any sorting technique)
// and then use a loop to print the words in sorted order. Hint: Use the
// read_line function to read each word, as in remind2.c.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 20

int read_line(char str[], int n);
void *my_malloc(size_t size);
int compare_words(const void *p, const void *q);

int main(void)
{
	char **words = NULL, word[WORD_LEN + 1];
	int num_words = 0, max_words = 1, i = 0;
	void *temp;

	words = my_malloc(max_words * sizeof *words);

	for (;;) {
		printf("Enter word: ");
		if (read_line(word, WORD_LEN) == 0)
			break;

		if (num_words == max_words) {
			max_words *= 2;
			temp = realloc(words, max_words * sizeof *words);
			if (temp == NULL) {
				printf("realloc: failed to reallocate memory\n");
				exit(EXIT_FAILURE);
			}
			words = temp;
		}
		words[i] = my_malloc(WORD_LEN + 1);
		strcpy(words[i++], word);
		num_words++;
	}

	qsort(words, num_words, sizeof *words, compare_words);

	printf("\nIn sorted order:");
	for (i = 0; i < num_words; i++) {
		printf(" %s", words[i]);
		free(words[i]);
	}
	free(words);
	printf("\n");

	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}

void *my_malloc(size_t size)
{
	void *p;

	if ((p = malloc(size)) == NULL) {
		printf("malloc: failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	return p;
}

int compare_words(const void *p, const void *q)
{
	return strcmp(*(const char **)p, *(const char **)q);
}
