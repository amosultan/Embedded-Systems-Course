/*
 *  File Name: main.c
 *  Description: Write a C program to find the area of a circle using macros.
 *
 *  Created on: Nov 13, 2020
 *  Author: Abdelrahman Sultan
 */


#include <stdio.h>
#include <math.h>

#define PI 3.14159
#define AREA_OF_CIRCLE(r) (PI) * pow((r), 2)

int main(void)
{
	/* Usage of setvbuf() or fflush() functions is related to a well known console bug in eclipse
	 * when using a printf() function right before a scanf() function.
     * For more info, checkout:
     * https://bugs.eclipse.org/bugs/show_bug.cgi?id=173732
     */

	setvbuf(stdout, NULL, _IONBF, 0);

	int r;
	double area;

	puts("Enter the radius of a circle:");
	scanf("%d", &r);

	area = AREA_OF_CIRCLE(r);

	printf("The area of the circle = %.2lf\n", area);

	return 0;
}
