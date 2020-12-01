/*
 *  File Name: main.c
 *	Description: Write a c program to add two integers.
 *
 *  Created on: Aug 26, 2020
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

	int num1, num2;
	long int sum;

	printf("%s", "Enter two integers: ");

	scanf("%i %i", &num1, &num2);

	sum = num1 + num2;

	printf("sum: %ld\n", sum);

	return 0;
}
