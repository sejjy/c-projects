// Modify Programming Project 9 from Chapter 8 so that it includes the following
// functions:
//
// void generate_random_walk(char walk[10][10]);
// void print_array(char walk[10][10]);
//
// main first calls generate_random_walk, which initializes the array to contain
// '.' characters and then replaces some of these characters by the letters A
// through Z, as described in the original project. main then calls print_array
// to display the array on the screen.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

int main(void)
{
	char walk[10][10];

	generate_random_walk(walk);
	print_array(walk);

	return 0;
}

void generate_random_walk(char walk[10][10])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			walk[i][j] = '.';
		}
	}

	char letter = 'A';
	i = 0;
	j = 0;
	bool u, d, l, r;

	walk[i][j] = letter++;

	srand((unsigned) time(NULL));

	while (letter <= 'Z') {
		u = d = l = r = false;

		if (i - 1 >= 0 && walk[i - 1][j] == '.') u = true;
		if (i + 1 < 10 && walk[i + 1][j] == '.') d = true;
		if (j - 1 >= 0 && walk[i][j - 1] == '.') l = true;
		if (j + 1 < 10 && walk[i][j + 1] == '.') r = true;

		if (!u && !d && !l && !r)
			break;

		switch (rand() % 4) {
			case 0: if (u) walk[--i][j] = letter++; break;
			case 1: if (d) walk[++i][j] = letter++; break;
			case 2: if (l) walk[i][--j] = letter++; break;
			case 3: if (r) walk[i][++j] = letter++; break;
		}
	}
}

void print_array(char walk[10][10])
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j > 0)
				printf(" ");
			printf("%c", walk[i][j]);
		}
		printf("\n");
	}
}
