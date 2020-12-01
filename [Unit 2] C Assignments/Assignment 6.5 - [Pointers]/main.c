/*
 *  File Name: main.c
 *  Description: Write a C program using a pointer to an array of pointers to structures.
 *
 *  Created on: Nov 13, 2020
 *  Author: Abdelrahman Sultan
 */


#include <stdio.h>

struct employee
{
	char name[20];
	int ID;
};

int main(void)
{
	/* Usage of setvbuf() or fflush() functions is related to a well known console bug in eclipse
	 * when using a printf() function right before a scanf() function.
	 * For more info, checkout:
	 * https://bugs.eclipse.org/bugs/show_bug.cgi?id=173732
	 */

	setvbuf(stdout, NULL, _IONBF, 0);

	struct employee emp1, emp2, emp3;
	struct employee *arr[3] = {&emp1, &emp2, &emp3};
	struct employee *(*arrPtr)[3] = &arr;
	size_t i;

	for(i = 0; i < 3; i++)
	{
		printf("Enter the data of employee no.%zu:\nName:", i + 1);
		scanf("%[^\n]%*c", ((*arrPtr)[i])->name);

		puts("ID:");
		scanf("%d", &((*((*arrPtr) + i))->ID));

		getchar();
	}

	puts("\nDisplaying the data of all employees:");

	for(i = 0; i < 3; i++)
	{
		printf("The data of employee no.%zu:\n", i + 1);

		printf("Name: %s\n", ((*arrPtr)[i])->name);
		printf("ID: %d\n", (*((*arrPtr) + i))->ID);
	}
	return 0;
}
