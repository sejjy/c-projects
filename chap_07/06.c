// Write a program that prints the values of sizeof(int), sizeof(short),
// sizeof(long), sizeof(float), sizeof(double) and sizeof(long double).

#include <stdio.h>

int main(void)
{
	printf("Size of int: %d\n", (int)sizeof(int));
	printf("Size of short: %d\n", (int)sizeof(short));
	printf("Size of long: %d\n", (int)sizeof(long));
	printf("Size of float: %d\n", (int)sizeof(float));
	printf("Size of double: %d\n", (int)sizeof(double));
	printf("Size of long double: %d\n", (int)sizeof(long double));

	return 0;
}
