/*
 *  File Name: main.c
 *	Description: Write a C program to reverse a string without using a library function.
 *
 *  Created on: Sep 8, 2020
 *  Author: Abdelrahman Sultan
 */


#include <stdio.h>
#include <string.h>

int main(void)
{
	/* Usage of setvbuf() or fflush() functions is related to a well known console bug in eclipse
	 * when using a printf() function right before a scanf() function.
	 * For more info, checkout:
	 * https://bugs.eclipse.org/bugs/show_bug.cgi?id=173732
	 */

	setvbuf(stdout, NULL, _IONBF, 0);

	char str[100], temp;
	size_t i, j;

	printf("%s", "Enter the string: ");
	scanf("%[^\n]*c", str);

	for (i = 0, j = (strlen(str) - 1); i < (strlen(str) / 2); i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}

	printf("The string after reversing it is: %s", str);

	return 0;
}
