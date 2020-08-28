/*
 * main.c
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

	int num;

	printf("Enter an integer: ");

	//fflush(stdout);

	scanf("%i", &num);

	printf("You entered %i\n", num);

	return 0;
}
