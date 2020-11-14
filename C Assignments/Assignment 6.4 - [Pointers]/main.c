/*
 *  File Name: main.c
 *  Description: Write a C program to print the elements of the array in reverse order using a pointer.
 *
 *  Created on: Nov 13, 2020
 *  Author: Abdelrahman Sultan
 */


#include <stdio.h>

#define MAX_SIZE 15

void reverseArray(int *const element1, int *const element2);

int main(void)
{
	/* Usage of setvbuf() or fflush() functions is related to a well known console bug in eclipse
	 * when using a printf() function right before a scanf() function.
	 * For more info, checkout:
	 * https://bugs.eclipse.org/bugs/show_bug.cgi?id=173732
	 */

	setvbuf(stdout, NULL, _IONBF, 0);

	int arr[MAX_SIZE], size;
	int *arrPtr = arr;
	size_t i, j;

	do
	{
		puts("Enter the number of elements to store in the array (MAX 15):");
		scanf("%d", &size);

	} while(size > 15);

	printf("Input %d numbers in the array\n", size);

	for(i = 0; i < size; i++)
	{
		printf("Element no.%zu: ", i + 1);
		scanf("%d", arrPtr + i);
	}

	for (i = 0, j = size - 1; i < (size / 2); i++, j--)
	{
		reverseArray(arrPtr + i, arrPtr + j);
	}

	puts("The elements in reverse :");

	for(i = 0; i < size; i++)
	{
		printf("Element no.%zu: %d\n", i + 1, *(arrPtr + i));
	}

	return 0;
}

void reverseArray(int *const element1, int *const element2)
{
	int temp;

	temp = *element1;
	*element1 = *element2;
	*element2 = temp;
}
