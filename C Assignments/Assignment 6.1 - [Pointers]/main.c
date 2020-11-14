/*
 *  File Name: main.c
 *  Description: Write a C program to demonstrate how to handle the pointers in the given sequence
 *
 *  Created on: Nov 13, 2020
 *  Author: Abdelrahman Sultan
 */


#include <stdio.h>

int main(void)
{
	int m = 29;
	int *ab = &m;

	printf("The address of the variable m = %p\n", &m);
	printf("The value of the variable m = %d\n", m);

	printf("The address contained in the pointer ab = %p\n", ab);
	printf("The content of the address contained in the pointer ab = %d\n", *ab);

	m = 34;

	printf("The address contained in the pointer ab = %p\n", ab);
	printf("The content of the address contained in the pointer ab = %d\n", *ab);

	*ab = 7;

	printf("The address of the variable m = %p\n", &m);
	printf("The value of the variable m = %d\n", m);

	return 0;
}
