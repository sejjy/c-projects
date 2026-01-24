// Modify the program of Programming Project 2 so that it prompts the user to
// enter the radius of the sphere.

#include <stdio.h>

#define VOLUME_FACTOR (4.0f / 3.0f)
#define PI 3.141592f

int main(void)
{
	// V = 4/3πr³
	
	float radius;

	printf("Sphere\n");
	printf("Solve for volume\n");

	printf("\nEnter radius: ");
	scanf("%f", &radius);

	printf("\nSolution\n");
	printf("V = 4/3πr³\n");
	printf("V = 4/3 * π * %.2f³\n", radius);

	float volume = VOLUME_FACTOR * PI * radius * radius * radius;

	printf("V ≈ %.2f\n", volume);

	return 0;
}
