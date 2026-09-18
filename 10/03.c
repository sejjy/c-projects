// Remove the num_in_rank, num_in_suit, and card_exists arrays from the
// poker.c program of Section 10.5. Have the program store the cards in a 5 × 2
// array instead. Each row of the array will represent a card. For example, if
// the array is named hand, then hand[0][0] will store the rank of the first
// card and hand[0][1] will store the suit of the first card.

/* Classifies a poker hand */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define NUM_CARDS 5
#define RANK 0
#define SUIT 1

/* external variables */
int hand[NUM_CARDS][2];
bool straight, flush, four, three;
int pairs; /* can be 0, 1, or 2 */

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);
bool card_exists(int rank, int suit, int cards_read);
void sort_cards_by_rank(void);

/**********************************************************
 * main: Calls read_cards, analyze_hand, and print_result *
 *       repeatedly.                                      *
 **********************************************************/
int main(void)
{
	for (;;) {
		read_cards();
		analyze_hand();
		print_result();
	}
}

/**********************************************************
 * read_cards: Reads the cards into the external variable *
 *             hand; checks for bad cards and duplicate   *
 *             cards.                                     *
 **********************************************************/
void read_cards(void)
{
	char ch, rank_ch, suit_ch;
	int rank = 0, suit = 0;
	bool bad_card;
	int cards_read = 0;

	while (cards_read < NUM_CARDS) {
		bad_card = false;

		printf("Enter a card: ");

		rank_ch = getchar();
		switch (rank_ch) {
			case '0':           exit(EXIT_SUCCESS);
			case '2':           rank = 0; break;
			case '3':           rank = 1; break;
			case '4':           rank = 2; break;
			case '5':           rank = 3; break;
			case '6':           rank = 4; break;
			case '7':           rank = 5; break;
			case '8':           rank = 6; break;
			case '9':           rank = 7; break;
			case 't': case 'T': rank = 8; break;
			case 'j': case 'J': rank = 9; break;
			case 'q': case 'Q': rank = 10; break;
			case 'k': case 'K': rank = 11; break;
			case 'a': case 'A': rank = 12; break;
			default: bad_card = true;
		}

		suit_ch = getchar();
		switch (suit_ch) {
			case 'c': case 'C': suit = 0; break;
			case 'd': case 'D': suit = 1; break;
			case 'h': case 'H': suit = 2; break;
			case 's': case 'S': suit = 3; break;
			default: bad_card = true;
		}

		while ((ch = getchar()) != '\n')
			if (ch != ' ') bad_card = true;

		if (bad_card)
			printf("Bad card; ignored.\n");
		else if (card_exists(rank, suit, cards_read))
			printf("Duplicate card; ignored.\n");
		else {
			hand[cards_read][RANK] = rank;
			hand[cards_read][SUIT] = suit;
			cards_read++;
		}
	}
}

/**********************************************************
 * analyze_hand: Determines whether the hand contains a   *
 *               straight, a flush, four-of-a-kind,       *
 *               and/or three-of-a-kind; determines the   *
 *               number of pairs; stores the results into *
 *               the external variables straight, flush,  *
 *               four, three, and pairs.                  *
 **********************************************************/
void analyze_hand(void)
{
	int i, j, kind;
	straight = true;
	flush = true;
	four = false;
	three = false;
	pairs = 0;

	sort_cards_by_rank();

	/* check for flush */
	for (i = 1; i < NUM_CARDS; i++) {
		if (hand[i][SUIT] != hand[0][SUIT]) {
			flush = false;
			break;
		}
	}

	/* check for straight */
	for (i = 0; i < NUM_CARDS - 1; i++) {
		if (hand[i][RANK] + 1 != hand[i + 1][RANK]) {
			straight = false;
			break;
		}
	}

	/* check for 4-of-a-kind, 3-of-a-kind, and pairs */
	for (i = 0; i < NUM_CARDS; i += kind) {
		kind = 1;
		for (j = i + 1; j < NUM_CARDS; j++) {
			if (hand[i][RANK] != hand[j][RANK])
				break;
			kind++;
		}
		if (kind == 4) four  = true;
		if (kind == 3) three = true;
		if (kind == 2) pairs++;
	}
}

/**********************************************************
 * print_result: Prints the classification of the hand,   *
 *               based on the values of the external      *
 *               variables straight, flush, four, three,  *
 *               and pairs.                               *
 **********************************************************/
void print_result(void)
{
	if (straight && flush) printf("Straight flush");
	else if (four)         printf("Four of a kind");
	else if (three &&
			 pairs == 1)   printf("Full house");
	else if (flush)        printf("Flush");
	else if (straight)     printf("Straight");
	else if (three)        printf("Three of a kind");
	else if (pairs == 2)   printf("Two pairs");
	else if (pairs == 1)   printf("Pair");
	else                   printf("High card");

	printf("\n\n");
}

/**********************************************************
 * card_exists: Determines if the card is already in      *
 *              hand.                                     *
 **********************************************************/
bool card_exists(int rank, int suit, int cards_read)
{
	for (int i = 0; i < cards_read; i++)
		if (hand[i][RANK] == rank && hand[i][SUIT] == suit)
			return true;
	return false;
}

/**********************************************************
 * sort_cards_by_rank: Sorts the cards in hand from       *
 *                     lowest to highest rank using       *
 *                     bubble sort                        *
 **********************************************************/
void sort_cards_by_rank(void)
{
	int i, j, rank, suit;

	for (i = 0; i < NUM_CARDS - 1; i++) {
		for (j = 0; j < NUM_CARDS - 1 - i; j++) {
			rank = hand[j][RANK];
			suit = hand[j][SUIT];
			if (rank > hand[j + 1][RANK]) {
				hand[j][RANK] = hand[j + 1][RANK];
				hand[j][SUIT] = hand[j + 1][SUIT];
				hand[j + 1][RANK] = rank;
				hand[j + 1][SUIT] = suit;
			}
		}
	}
}
