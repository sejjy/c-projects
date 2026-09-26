// Modify Programming Project 11 from Chapter 7 so that it includes the
// following function:
//
// void reverse_name(char *name);
//
// The function expects name to point to a string containing a first name
// followed by a last name. It modifies the string so that the last name comes
// first, followed by a comma, a space, the first initial, and a period. The
// original string may contain extra spaces before the first name, between the
// first and last names, and after the last name.

#include <stdio.h>

#define NAME_LEN 100

void reverse_name(char *name);

int main(void)
{
	char name[NAME_LEN + 1];

	printf("Enter first and last name: ");
	fgets(name, sizeof(name), stdin);

	reverse_name(name);

	return 0;
}

void reverse_name(char *name)
{
	while (*name == ' ')
		name++;

	char initial = *name++;

	while (*name && *name++ != ' ')
		;
	while (*name == ' ')
		name++;

	while (*name && *name != ' ' && *name != '\n')
		printf("%c", *name++);
	printf(", %c.\n", initial);
}
