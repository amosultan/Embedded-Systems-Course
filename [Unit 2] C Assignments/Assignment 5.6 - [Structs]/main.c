/*
 *  File Name: main.c
 *  Description: Find the output of the program
 *
 *  Created on: Nov 13, 2020
 *  Author: Abdelrahman Sultan
 */


#include <stdio.h>

union
{
	char name [32];
	float salary;
	int work_no;
}u;

struct
{
	char name [32];
	float salary;
	int work_no;
}s;

int main(void)
{
	/*size of union: 32*/
	printf("size of union: %zu\n", sizeof(u));

	/*size of structure 40*/
	printf("size of structure %zu\n", sizeof(s));

	return 0;
}
