// Modify Programming Project 6 from Chapter 10 so that it includes the
// following function:
//
// int evaluate_RPN_expression(const char *expression);
//
// The function returns the value of the RPN expression pointed to by
// expression.

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define EXPR_LEN   100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);
int evaluate_RPN_expression(const char *expression);

int main(void)
{
	char expression[EXPR_LEN];

	for (;;) {
		printf("Enter an RPN expression: ");
		fgets(expression, sizeof(expression), stdin);
		printf("Value of expression: %d\n",
				evaluate_RPN_expression(expression));
		make_empty();
	}

	return 0;
}

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(int i)
{
	if (is_full()) {
		stack_overflow();
		exit(EXIT_FAILURE);
	}

	contents[top++] = i;
}

int pop(void)
{
	if (is_empty()) {
		stack_underflow();
		exit(EXIT_FAILURE);
	}

	return contents[--top];
}

void stack_overflow(void)
{
	printf("Expression is too complex\n");
}

void stack_underflow(void)
{
	printf("Not enough operands in expression\n");
}

int evaluate_RPN_expression(const char *expression)
{
	int opr1, opr2;

	while (*expression) {
		if (*expression >= '0' && *expression <= '9')
			push(*expression - '0');
		else
			switch (*expression) {
				case '+': opr2 = pop(); opr1 = pop(); push(opr1 + opr2); break;
				case '-': opr2 = pop(); opr1 = pop(); push(opr1 - opr2); break;
				case '*': opr2 = pop(); opr1 = pop(); push(opr1 * opr2); break;
				case '/': opr2 = pop(); opr1 = pop(); push(opr1 / opr2); break;
				case '=': return pop();
				case ' ': break;
				default:  exit(EXIT_SUCCESS);
			}

		expression++;
	}

	exit(EXIT_FAILURE);
}
