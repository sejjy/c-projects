// Write a program that computes the volume of a sphere with a 10-meter radius, using the for-
// mula v = 4/3πr³. Write the fraction 4/3 as 4.0f/3.0f. (Try writing it as 4/3. What hap-
// pens?) Hint: C doesn’t have an exponentiation operator, so you’ll need to multiply r by itself
// twice to compute r³.

#include <stdio.h>

#define VOLUME_FACTOR (4.0f / 3.0f)
#define PI 3.141592f

int main(void)
{
	printf("Sphere\n");
	printf("Radius = 10\n");
	printf("Volume = %.2f\n", VOLUME_FACTOR * PI * 10 * 10 * 10);

	return 0;
}
