/*
 * main.c
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

	char operator;
	float num1, num2;
	double result;

	printf("Enter operator either + or - or * or /: ");

	scanf("%c", &operator);

	printf("\nEntere two operands: ");

	scanf("%f %f", &num1, &num2);

	switch (operator)
	{
		case '+':
			result = num1 + num2;
			printf("%f %c %f = %lf", num1, operator, num2, result);
			break;

		case '-':
			result = num1 - num2;
			printf("%f %c %f = %lf", num1, operator, num2, result);
			break;

		case '*':
			result = num1 * num2;
			printf("%f %c %f = %lf", num1, operator, num2, result);
			break;

		case '/':
			result = num1 / num2;
			printf("%f %c %f = %lf", num1, operator, num2, result);
			break;

		default:
			break;
	}
	return 0;
}
