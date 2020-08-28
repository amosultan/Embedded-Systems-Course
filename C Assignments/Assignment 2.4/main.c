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

	float num;

	printf("Enter a number: ");

	scanf("%f", &num);

	if (num > 0)
		printf("%f is positive.\n", num);

	else if (num < 0)
		printf("%f is negative.\n", num);

	else
		printf("You entered zero.\n");

	return 0;
}
