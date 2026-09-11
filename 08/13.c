// Modify Programming Project 11 from Chapter 7 so that the program labels its
// output:
//
// Enter a first and last name: Lloyd Fosdick
// You entered the name: Fosdick, L.
//
// The program will need to store the last name (but not the first name) in an
// array of characters until it can be printed. You may assume that the last
// name is no more than 20 characters long.

#include <stdio.h>

#define SIZE 20

int main(void)
{
	char initial;

	printf("Enter a first and last name: ");
	scanf(" %c", &initial);

	char c;

	while ((c = getchar()) != ' ')
		;

	while ((c = getchar()) == ' ')
		;

	char last[SIZE];
	int i = 0;

	do {
		last[i++] = c;
	} while ((c = getchar()) != '\n' && c != ' ');

	printf("You entered the name: ");

	for (int j = 0; j < i; j++) {
		printf("%c", last[j]);
	}

	printf(", %c.\n", initial);

	return 0;
}
