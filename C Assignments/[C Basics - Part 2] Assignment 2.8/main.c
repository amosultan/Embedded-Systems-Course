/*
 *  File Name: main.c
 *	Description: Write a C program of a simple calculator using switch statement.
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

	printf("%s", "Enter an operator, either +, -, * or /: ");

	scanf("%c", &operator);

	printf("%s", "\nEntere two operands: ");

	scanf("%f %f", &num1, &num2);

	switch (operator)
	{
		case '+':
			result = num1 + num2;
			printf("%.2f %c %.2f = %.2lf", num1, operator, num2, result);
			break;

		case '-':
			result = num1 - num2;
			printf("%.2f %c %.2f = %.2lf", num1, operator, num2, result);
			break;

		case '*':
			result = num1 * num2;
			printf("%.2f %c %.2f = %.2lf", num1, operator, num2, result);
			break;

		case '/':
			result = num1 / num2;
			printf("%.2f %c %.2f = %.2lf", num1, operator, num2, result);
			break;

		default:
			break;
	}
	return 0;
}
