/*
 *  File Name: main.c
 *	Description: Write a C program to search for an element in an array.
 *
 *  Created on: Sep 8, 2020
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

	size_t num, i, flag = 0;
	int target;

	printf("%s", "Enter the number of elements: ");
	scanf("%u", &num);

	int arr[num];

	for(i = 0; i < num; i++)
	{
		printf("Enter element number %u: ", i+1);
		scanf("%d", &arr[i]);
	}

	printf("%s", "Enter the element to be searched: ");
	scanf("%d", &target);

	for (i = 0; i < num; i++)
	{
		if (arr[i] == target)
		{
			flag = 1;
			break;
		}
	}

	if (flag == 1)
		printf("Number found at location: %u\n", i + 1);
	else
		puts("Not Found");

	return 0;
}
