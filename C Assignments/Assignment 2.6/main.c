/*
 * 	File Name: main.c
 *	Description: Write a C program to find the sum of natural numbers up to an input integer.
 *
 *  Created on: Aug 27, 2020
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

	int num, i;
	long int sum = 0;

	printf("%s", "Enter an integer: ");

	scanf("%i", &num);

	for(i = 0; i <= num; i++)
	{
		sum += i;
	}

	printf("Sum = %ld\n", sum);

	return 0;
}
