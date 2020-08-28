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

	int num, i;
	long int Factorial = 1;

	printf("Enter an integer: ");

	scanf("%d", &num);

	if (num < 0)
		printf("Error!! Factorial of negative number doesn't exist\n");

	else if (num > 0)
	{
		for (i = 1; i <= num; i++)
			Factorial *= i;

		printf("Factorial = %ld\n", Factorial);
	}

	else
		printf("Factorial = 1\n");

	return 0;
}
