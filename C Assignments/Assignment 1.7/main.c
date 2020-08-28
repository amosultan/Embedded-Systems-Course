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

	int num1, num2;

	printf("Enter value of first number: ");

	scanf("%i", &num1);

	printf("Enter the value of the second number: ");

	scanf("%i", &num2);

	/*num1 = num1 + num2;
	num2 = num1 - num2;
	num1 = num1 - num2;
	*/


	 //Another way to swap 2 numbers without using temp variable
	 num1 = num1 ^ num2;
	 num2 = num1 ^ num2;
	 num1 = num1 ^ num2;



	printf("After swapping the value of the first number = %i\n"
				"After swapping the value of the second number = %i\n", num1, num2);

	return 0;
}
