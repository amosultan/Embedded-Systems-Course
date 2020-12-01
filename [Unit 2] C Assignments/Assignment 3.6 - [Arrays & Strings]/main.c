/*
 *  File Name: main.c
 *	Description: Write a C program to find the frequency of a character in a string.
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

	char str[100], character;
	size_t i, freq = 0;

	printf("%s", "Enter a string: ");
	fgets(str, 100, stdin);

	printf("Enter a character to find its frequency: ");
	scanf("%c", &character);

	for (i = 0; i < strlen(str); i++)
		if(str[i] == character)
			freq++;

	printf("Frequency of %c is %u\n", character, freq);

	return 0;
}
