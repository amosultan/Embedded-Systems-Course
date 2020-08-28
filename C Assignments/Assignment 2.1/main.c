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

	int num;

	printf("Enter an integer you want to check: ");

	scanf("%i", &num);

	if(num % 2 == 0)
		printf("%i is even.\n", num);

	else
		printf("%i is odd.\n", num);

	return 0;
}
