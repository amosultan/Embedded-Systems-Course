/*
 * 	File Name: main.c
 *	Description: Write a C program to multiply two floating point numbers.
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

	float num1, num2;
	double product;

	printf("%s", "Enter two numbers: ");

	scanf("%f %f", &num1, &num2);

	product = num1 * num2;

	printf("%.3lf", product);

	return 0;
}
