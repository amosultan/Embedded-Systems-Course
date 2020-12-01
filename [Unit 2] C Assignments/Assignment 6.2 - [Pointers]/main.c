/*
 *  File Name: main.c
 *  Description: Write a C program to print all the alphabets using a pointer.
 *
 *  Created on: Nov 13, 2020
 *  Author: Abdelrahman Sultan
 */


#include <stdio.h>

int main(void)
{
	char alpha = 'A';
	char *alphaPtr = &alpha;

	size_t i;

	for(i = 0; i <= 'Z' - 'A'; i++)
	{
		printf("%c ", *alphaPtr + i);
	}

	return 0;
}
