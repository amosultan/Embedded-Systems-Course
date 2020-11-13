/*
 *  File Name: main.c
 *  Description: Write a C program to add two distances using inch-feet system with structs.
 *  
 *  Created on: Nov 9, 2020
 *  Author: Abdelrahman Sultan
 */


#include <stdio.h>
#include <math.h>

struct distance
{
	int feet;
	float inch;
};

int main(void)
{
	/* Usage of setvbuf() or fflush() functions is related to a well known console bug in eclipse
	 * when using a printf() function right before a scanf() function.
	 * For more info, checkout:
	 * https://bugs.eclipse.org/bugs/show_bug.cgi?id=173732
	 */

	setvbuf(stdout, NULL, _IONBF, 0);

	struct distance D1, D2;

	puts("First Distance:");
	printf("%s", "Enter feet: ");
	scanf("%d", &D1.feet);

	printf("%s", "Enter inch: ");
	scanf("%f", &D1.inch);

	puts("Second Distance:");
	printf("%s", "Enter feet: ");
	scanf("%d", &D2.feet);

	printf("%s", "Enter inch: ");
	scanf("%f", &D2.inch);

	printf("Sum of the two distances = %d' - %.2f\"\n",
			D1.feet + D2.feet + (int)((D1.inch + D2.inch) / 12), fmod((D1.inch + D2.inch), 12.0));
	return 0;
}
