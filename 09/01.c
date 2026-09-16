// Write a program that asks the user to enter a series of integers (which it
// stores in an array), then sorts the integers by calling the function
// selection_sort. When given an array with n elements, selection_sort must do
// the following:
// 1. Search the array to find the largest element, then move it to the last
// position in the array.
// 2. Call itself recursively to sort the first n – 1 elements of the array.

#include <stdio.h>

#define N 10

void selection_sort(int a[], int n);

int main(void)
{
	printf("Enter %d integers to be sorted: ", N);

	int i = 0;
	int a[N];

	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	selection_sort(a, N - 1);

	printf("In sorted order:");

	for (i = 0; i < N; i++) {
		printf(" %d", a[i]);
	}

	printf("\n");

	return 0;
}

void selection_sort(int a[], int n)
{
	if (n == 0) {
		return;
	}

	int largest = 0;

	for (int i = 1; i <= n; i++) {
		if (a[i] > a[largest]) {
			largest = i;
		}
	}

	int last = a[n];

	a[n] = a[largest];
	a[largest] = last;

	selection_sort(a, n - 1);
}
