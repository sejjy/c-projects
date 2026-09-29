#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
	char ch;
	int op1, op2;

	for (;;) {
		printf("Enter an RPN expression: ");

		for (;;) {
			scanf(" %c", &ch);

			if (ch >= '0' && ch <= '9')
				push(ch - '0');
			else if (ch == '+') { op2 = pop(); op1 = pop(); push(op1 + op2); }
			else if (ch == '-') { op2 = pop(); op1 = pop(); push(op1 - op2); }
			else if (ch == '*') { op2 = pop(); op1 = pop(); push(op1 * op2); }
			else if (ch == '/') { op2 = pop(); op1 = pop(); push(op1 / op2); }
			else if (ch == '=') {
				printf("Value of expression: %d\n", pop());
				make_empty();
				break;
			}
			else
				exit(EXIT_SUCCESS);
		}
	}

	return 0;
}
