/*
 * 	File Name: main.c
 *	Description: Write a C program to check whether a character is alphabet or not.
 *
 *  Created on: Aug 27, 2020
 *  Author: Abdelrahman Sultan
 */


#include <stdio.h>
#include <ctype.h>

int main(void)
{
	/* Usage of setvbuf() or fflush() functions is related to a well known console bug in eclipse
	 * when using a printf() function right before a scanf() function.
	 * For more info, checkout:
	 * https://bugs.eclipse.org/bugs/show_bug.cgi?id=173732
	 */

	setvbuf(stdout, NULL, _IONBF, 0);

	char c;

	printf("%s", "Enter a character: ");

	scanf("%c", &c);

	if (isalpha(c))
		printf("%c is an alphabet.\n", c);

	else
		printf("%c is not an alphabet.\n", c);

	return 0;
}
