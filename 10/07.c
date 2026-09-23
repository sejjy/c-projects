// Write a program that prompts the user for a number and then displays the
// number, using characters to simulate the effect of a seven-segment display:
//
// Enter a number: 491-9014
//      _       _   _
// |_| |_|   | |_| | |   | |_|
//   |  _|   |  _| |_|   |   |
//
// Characters other than digits should be ignored. Write the program so that the
// maximum number of digits is controlled by a macro named MAX_DIGITS, which has
// the value 10. If the number contains more than this number of digits, the
// extra digits are ignored. Hints: Use two external arrays. One is the segments
// array (see Exercise 6 in Chapter 8), which stores data representing the
// correspondence between digits and segments. The other array, digits, will be
// an array of characters with 4 rows (since each segmented digit is four
// characters high) and MAX_DIGITS * 4 columns (digits are three characters
// wide, but a space is needed between digits for readability). Write your
// program as four functions: main, clear_digits_array, process_digit, and
// print_digits_array. Here are the prototypes for the latter three functions:
//
// void clear_digits_array(void);
// void process_digit(int digit, int position);
// void print_digits_array(void);
//
// clear_digits_array will store blank characters into all elements of the
// digits array. process_digit will store the seven-segment representation of
// digit into a specified position in the digits array (positions range from 0
// to MAX_DIGITS – 1). print_digits_array will display the rows of the digits
// array, each on a single line, producing output such as that shown in the
// example.

#include <stdio.h>

#define MAX_DIGITS 10
#define ROWS 4
#define MAX_COLUMNS (MAX_DIGITS * 4)

const int segments[10][7] = {
	{1, 1, 1, 1, 1, 1, 0}, // 0
	{0, 1, 1, 0, 0, 0, 0}, // 1
	{1, 1, 0, 1, 1, 0, 1}, // 2
	{1, 1, 1, 1, 0, 0, 1}, // 3
	{0, 1, 1, 0, 0, 1, 1}, // 4
	{1, 0, 1, 1, 0, 1, 1}, // 5
	{1, 0, 1, 1, 1, 1, 1}, // 6
	{1, 1, 1, 0, 0, 0, 0}, // 7
	{1, 1, 1, 1, 1, 1, 1}, // 8
	{1, 1, 1, 1, 0, 1, 1}, // 9
};
char digits[ROWS][MAX_COLUMNS];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
	clear_digits_array();

	printf("Enter a number: ");

	int position = 0;
	int digit;

	while (position < MAX_DIGITS && (digit = getchar()) != '\n') {
		if (digit >= '0' && digit <= '9') {
			process_digit(digit - '0', position);
			position++;
		}
	}

	print_digits_array();

	return 0;
}

void clear_digits_array(void)
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < MAX_COLUMNS; j++)
			digits[i][j] = ' ';
}

void process_digit(int digit, int position)
{
	int start = position * 4;

	// row 1
	if (segments[digit][0]) digits[0][start + 1] = '_';

	// row 2
	if (segments[digit][5]) digits[1][start]     = '|';
	if (segments[digit][6]) digits[1][start + 1] = '_';
	if (segments[digit][1]) digits[1][start + 2] = '|';

	// row 3
	if (segments[digit][4]) digits[2][start]     = '|';
	if (segments[digit][3]) digits[2][start + 1] = '_';
	if (segments[digit][2]) digits[2][start + 2] = '|';

	// row 4 is blank since the example uses only 3 rows
}

void print_digits_array(void)
{
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < MAX_COLUMNS; j++)
			printf("%c", digits[i][j]);
		printf("\n");
	}
}
