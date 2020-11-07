/*
 * 	File Name: main.c
 *	Description: Write a C program to check whether a number is positive or negative.
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

	float num;

	printf("%s", "Enter a number: ");

	scanf("%f", &num);

	if (num > 0)
		printf("%.2f is positive.\n", num);

	else if (num < 0)
		printf("%.2f is negative.\n", num);

	else
		puts("You entered zero.");

	return 0;
}
