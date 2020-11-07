/*
 * 	File Name: main.c
 *	Description: Write a C program to find the largest number between 3 numbers.
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

	double num1, num2, num3;

	printf("%s", "Enter three numbers: ");

	scanf("%lf %lf %lf", &num1, &num2, &num3);

	if (num1 >= num2 && num1 >= num3)
		printf("Largest number = %.2lf\n", num1);

	else if (num2 >= num1 && num2 >= num3)
		printf("Largest number = %.2lf\n", num2);

	else if (num3 >= num1 && num3 >= num2)
		printf("Largest number = %.2lf\n", num3);

	return 0;
}
