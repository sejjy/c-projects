#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct node {
	struct node *next;
	char word[];
};

struct node *line = NULL;

int line_len = 0;
int num_words = 0;

void clear_line(void)
{
	struct node *temp;
	while (line != NULL) {
		temp = line;
		line = line->next;
		free(temp);
	}
	line_len = 0;
	num_words = 0;
}

void add_word(const char *word)
{
	struct node *new_word, *p;

	new_word = malloc(sizeof *new_word + strlen(word) + 1);
	if (new_word == NULL) {
		printf("malloc: failed to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	strcpy(new_word->word, word);
	new_word->next = NULL;

	if (line == NULL)
		line = new_word;
	else {
		for (p = line; p->next != NULL; p = p->next)
			;
		p->next = new_word;
	}

	if (num_words > 0)
		line_len++;

	line_len += strlen(word);
	num_words++;
}

int space_remaining(void)
{
	return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
	struct node *p;
	int extra_spaces, spaces_to_insert, i;
	extra_spaces = MAX_LINE_LEN - line_len;

	for (p = line; p != NULL; p = p->next) {
		printf("%s", p->word);
		if (p->next != NULL) {
			spaces_to_insert = extra_spaces / (num_words - 1);
			for (i = 1; i <= spaces_to_insert + 1; i++)
				putchar(' ');
			extra_spaces -= spaces_to_insert;
			num_words--;
		}
	}
	putchar('\n');
}

void flush_line(void)
{
	struct node *p;

	if (line_len > 0) {
		for (p = line; p != NULL; p = p->next) {
			if (p != line)
				putchar(' ');
			printf("%s", p->word);
		}
	}
	putchar('\n');
}
