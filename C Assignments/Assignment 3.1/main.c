/*
 *  File Name: main.c
 *	Description: Write a C program to find the sum of two matrices of order 2 by 2 using arrays.
 *
 *  Created on: Sep 6, 2020
 *  Author: Abdelrahman Sultan
 */


#include <stdio.h>

int main(void)
{
	/* Usage of setvbuf() or fflush() functions is related to a well known console bug in eclipse
	 * when using a printf() function right before a scanf() function.
	 * For more info, checkout:
	 * https://bugs.eclipse.org/bugs/show_bug.cgi?id=173732
	 */

	setvbuf(stdout, NULL, _IONBF, 0);

	float m1[2][2], m2[2][2], mSum[2][2];
	size_t i, j;

	puts("Enter the elements of the first matrix:");

	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
		{
			printf("Enter a%u%u: ", i + 1, j + 1);
			scanf("%f", &m1[i][j]);
		}

	puts("Enter the elements of the second matrix:");

	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
		{
			printf("Enter b%u%u: ", i + 1, j + 1);
			scanf("%f", &m2[i][j]);
		}

	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
		{
			mSum[i][j] = m1[i][j] + m2[i][j];
		}

	printf("\nSum of Matrix:\n%.1f\t%.1f\n%.1f\t%.1f\n", mSum[0][0], mSum[0][1], mSum[1][0], mSum[1][1]);

	return 0;
}
