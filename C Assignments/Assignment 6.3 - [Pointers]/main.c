/*
 *  File Name: main.c
 *  Description: Write a C program to reverse a string using pointer.
 *
 *  Created on: Nov 13, 2020
 *  Author: Abdelrahman Sultan
 */


#include <stdio.h>
#include <string.h>

#define SIZE 50

void reverseString(char *const charPtr1, char *const charPtr2);

int main(void)
{
	/* Usage of setvbuf() or fflush() functions is related to a well known console bug in eclipse
	 * when using a printf() function right before a scanf() function.
	 * For more info, checkout:
	 * https://bugs.eclipse.org/bugs/show_bug.cgi?id=173732
	 */

	setvbuf(stdout, NULL, _IONBF, 0);

	char stringArr[SIZE];
	char *stringPtr = stringArr;
	size_t len, i, j;

	puts("Enter a string:");

	if(fgets(stringArr, SIZE - 1, stdin) != NULL)
	{
		len = strlen(stringArr);

		if(stringArr[len - 1] == '\n')
			stringArr[--len] = '\0';

		for(i = 0, j = len - 1; i < (len / 2); i++, j--)
		{
			reverseString(stringPtr + i, stringPtr + j);
		}

		puts("The string after being reversed:");
		printf("%s\n", stringPtr);
	}

	return 0;
}

void reverseString(char *const charPtr1, char *const charPtr2)
{
	char temp;

	temp = *charPtr1;
	*charPtr1 = *charPtr2;
	*charPtr2 = temp;
}
