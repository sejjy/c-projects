// Modify the program of Programming Project 2 so that it prompts the user to enter the radius
// of the sphere.

#include <stdio.h>

#define PI 3.141592f

int main(void)
{
	// V = 4/3πr³
	
	float radius, volume;

	printf("Sphere\n");
	printf("Solve for volume\n");

	printf("\nEnter radius: ");
	scanf("%f", &radius);

	printf("\nSolution\n");
	printf("V = 4/3πr³\n");
	printf("V = 4/3 * π * %.2f³\n", radius);

	volume = 4.0f / 3.0f * PI * radius * radius * radius;

	printf("V ≈ %.2f\n", volume);

	return 0;
}
