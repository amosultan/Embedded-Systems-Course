/*
 *  File Name: main.c
 *	Description: Write a C program that takes a matrix as input from the user and finds its transpose.
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

	size_t row, col, i, j;

	do
	{
		printf("%s", "Enter the row and column of the matrix: ");
		scanf("%u %u", &row, &col);
	}
	while (row <=0 && col <=0);

	int m[row][col], transMat[col][row];

	printf("%s", "\nEnter the elements of the matrix:\n");

	for(i = 0; i < row; i++)
		for(j = 0; j < col; j++)
		{
			printf("Enter element[%u][%u]: ", i + 1, j + 1);
			scanf("%d", &m[i][j]);
		}

	puts("\nEntered Matrix:");

	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
			printf("%d\t", m[i][j]);

		puts("\n");
	}

	for(i = 0; i < row; i++)
		for(j = 0; j < col; j++)
		{
			transMat[j][i] = m[i][j];
		}

	puts("\n\n Transpose of the matrix:\n");

	for (i = 0; i < col; i++)
	{
		for(j = 0; j < row; j++)
			printf("%d\t", transMat[i][j]);

		puts("\n");
	}

	return 0;
}
