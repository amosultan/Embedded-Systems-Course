/*
 * 	main.c
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

	double num1, num2, temp;

	printf("Enter value of first number: ");

	scanf("%lf", &num1);

	printf("Enter the value of the second number: ");

	scanf("%lf", &num2);

	temp = num1;
	num1 = num2;
	num2 = temp;

	printf("After swapping the value of the first number = %.2lf\n"
			"After swapping the value of the second number = %.2lf\n", num1, num2);

	return 0;
}
