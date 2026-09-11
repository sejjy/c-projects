// Modify Programming Project 7 so that it prompts for five quiz grades for each
// of five students, then computes the total score and average score for each
// student, and the average score, high score, and low score for each quiz.

#include <stdio.h>

#define STUDENTS 5
#define QUIZZES 5

int main(void)
{
	int scores[STUDENTS][QUIZZES];
	int i, j;

	for (i = 0; i < STUDENTS; i++) {
		printf("Enter quiz grades for student %d: ", i + 1);

		for (j = 0; j < QUIZZES; j++) {
			scanf("%d", &scores[i][j]);
		}
	}

	int total, average;

	printf("\n");

	for (i = 0; i < STUDENTS; i++) {
		total = 0;

		for (j = 0; j < QUIZZES; j++) {
			total += scores[i][j];
		}

		average = total / QUIZZES;

		printf("Total and average scores for student %d: %3d %3d\n", i + 1,
				total, average);
	}

	int high, low;

	printf("\n");

	for (i = 0; i < QUIZZES; i++) {
		total = 0;
		high = scores[0][i];
		low = scores[0][i];

		for (j = 0; j < STUDENTS; j++) {
			total += scores[j][i];

			if (scores[j][i] > high) {
				high = scores[j][i];
			}

			if (scores[j][i] < low) {
				low = scores[j][i];
			}
		}

		average = total / STUDENTS;

		printf("Average, high, and low scores for quiz %d: %3d %3d %3d\n",
				i + 1, average, high, low);
	}

	return 0;
}
