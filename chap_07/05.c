// In the SCRABBLE Crossword Game, players form words using small tiles, each
// containing a letter and a face value. The face value varies from one letter
// to another, based on the letter’s rarity. (Here are the face values: 1:
// AEILNORSTU, 2: DG, 3: BCMP, 4: FHVWY, 5: K, 8: JX, 10: QZ.) Write a program
// that computes the value of a word by summing the values of its letters:
//
// Enter a word: pitfall
// Scrabble value: 12
//
// Your program should allow any mixture of lower-case and upper-case letters in
// the word. Hint: Use the toupper library function.

#include <ctype.h>
#include <stdio.h>

int main(void)
{
	printf("Enter a word: ");

	char ch;
	int value = 0;

	while ((ch = getchar()) != '\n') {
		switch (toupper(ch)) {
			case 'Q': case 'Z':
				value += 10;
				break;
			case 'J': case 'X':
				value += 8;
				break;
			case 'K':
				value += 5;
				break;
			case 'F': case 'H': case 'V': case 'W': case 'Y':
				value += 4;
				break;
			case 'B': case 'C': case 'M': case 'P':
				value += 3;
				break;
			case 'D': case 'G':
				value += 2;
				break;
			default:
				value += 1;
				break;
		}
	}

	printf("Scrabble value: %d\n", value);

	return 0;
}
