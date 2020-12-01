/*
 *  File Name: main.c
 *  Description: Write a C program to store and display the data of 10 students using structs.
 *  
 *  Created on: Nov 9, 2020
 *  Author: Abdelrahman Sultan
 */


#include <stdio.h>

#define SIZE 3

struct student
{
	int roll;
	char name[20];
	double mark;
};

int main(void)
{
	/* Usage of setvbuf() or fflush() functions is related to a well known console bug in eclipse
	 * when using a printf() function right before a scanf() function.
	 * For more info, checkout:
	 * https://bugs.eclipse.org/bugs/show_bug.cgi?id=173732
	 */

	setvbuf(stdout, NULL, _IONBF, 0);

	size_t i;
	struct student arr[SIZE];

	puts("Enter Students' information:");

	for(i = 0; i < SIZE; i++)
	{
		arr[i].roll = i + 1;

		printf("For roll number %d:\nEnter student's name: ", arr[i].roll);
		scanf("%[^\n]%*c", arr[i].name);

		printf("%s", "Enter student's mark: ");
		scanf("%lf%*c", &arr[i].mark);

		/* can be used instead of %*c to get rid of the trailing enter (\n)
		 * after inputing the double
		 * getchar();
		 */

	}

	for(i = 0; i < SIZE; i++)
	{
		printf("\nInformation for roll number %d:\nStudent's Name: %s\nStudent's mark: %.2lf",
				arr[i].roll, arr[i].name, arr[i].mark);

	}

	return 0;
}
