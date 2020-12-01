/*
 *  File Name: main.c
 *	Description: C program to reverse a sentence using recursion.
 *
 *  Created on: Sep 9, 2020
 *  Author: Abdelrahman Sultan
 */


#include <stdio.h>
#include <string.h>

#define SIZE 100

char *strRev(const char str[]);

int main(void)
{
	/* Usage of setvbuf() or fflush() functions is related to a well known console bug in eclipse
	 * when using a printf() function right before a scanf() function.
	 * For more info, checkout:
	 * https://bugs.eclipse.org/bugs/show_bug.cgi?id=173732
	 */

	setvbuf(stdout, NULL, _IONBF, 0);

	char str[SIZE];

	puts("Enter a sentence:");
	scanf("%[^\n]*s", str);

	printf("The string after reversing it is: %s", strRev(str));

	return 0;
}

char *strRev(const char str[])
{
	static size_t i = 0;
	static char reversedStr[100];

	if(*str != '\0')
	{
		strRev(str + 1);
		reversedStr[i++] = *str;
	}

	return reversedStr;
}
