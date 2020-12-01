/*
 *  File Name: main.c
 *	Description: Write a C program to find the length of a string.
 *
 *  Created on: Sep 8, 2020
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

	char str[100];
	size_t i = 0;

	printf("%s", "Enter a string: ");
	scanf("%[^\n]*c", str);

	while(str[i] != '\0')
	{
		i++;
	}

	printf("Length of string: %u\n", i);

	return 0;
}
