// Write a program that generates a “random walk” across a 10 × 10 array. The
// array will contain characters (all '.' initially). The program must randomly
// “walk” from element to element, always going up, down, left, or right by one
// element. The elements visited by the program will be labeled with the letters
// A through Z, in the order visited. Here’s an example of the desired output:
//
// A . . . . . . . . .
// B C D . . . . . . .
// . F E . . . . . . .
// H G . . . . . . . .
// I . . . . . . . . .
// J . . . . . . . Z .
// K . . R S T U V Y .
// L M P Q . . . W X .
// . N O . . . . . . .
// . . . . . . . . . .
//
// Hint: Use the srand and rand functions (see deal.c) to generate random
// numbers. After generating a number, look at its remainder when divided by 4.
// There are four possible values for the remainder—0, 1, 2, and 3—indicating
// the direction of the next move. Before performing a move, check that (a) it
// won’t go outside the array, and (b) it doesn’t take us to an element that
// already has a letter assigned. If either condition is violated, try moving in
// another direction. If all four directions are blocked, the program must
// terminate. Here’s an example of premature termination:
//
// A B G H I . . . . .
// . C F . J K . . . .
// . D E . M L . . . .
// . . . . N O . . . .
// . . W X Y P Q . . .
// . . V U T S R . . .
// . . . . . . . . . .
// . . . . . . . . . .
// . . . . . . . . . .
// . . . . . . . . . .
//
// Y is blocked on all four sides, so there’s no place to put Z.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	char letter = 'A';
	char map[10][10] = {0};
	int i = 0;
	int j = 0;
	bool u, d, l, r;

	map[i][j] = letter++;

	srand((unsigned) time(NULL));

	while (letter <= 'Z') {
		u = d = l = r = false;

		if (i - 1 >= 0 && !map[i - 1][j]) u = true;
		if (i + 1 < 10 && !map[i + 1][j]) d = true;
		if (j - 1 >= 0 && !map[i][j - 1]) l = true;
		if (j + 1 < 10 && !map[i][j + 1]) r = true;

		if (!u && !d && !l && !r)
			break;

		switch (rand() % 4) {
			case 0: if (u) map[--i][j] = letter++; break;
			case 1: if (d) map[++i][j] = letter++; break;
			case 2: if (l) map[i][--j] = letter++; break;
			case 3: if (r) map[i][++j] = letter++; break;
		}
	}

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (map[i][j] == 0)
				map[i][j] = '.';
			if (j > 0)
				printf(" ");
			printf("%c", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}
