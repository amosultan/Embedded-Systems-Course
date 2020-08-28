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

	char character;

	printf("Enter a character: ");

	scanf("%c", &character);

	printf("ASCII value of %c = %i\n", character, character);

	return 0;
}
