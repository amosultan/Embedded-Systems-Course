/*
 *  File Name: main.c
 *  Description: Write a C Program to store information about a student then display it.
 *
 *  Created on: Nov 8, 2020
 *  Author: Abdelrahman Sultan
 */

#include <stdio.h>

struct student
{
	char name[100];
	int roll;
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

	struct student s1;

	puts("Enter student's information:");

	printf("%s", "Enter student's name: ");
	scanf("%[^\n]*s", s1.name);

	printf("Enter student's roll number: ");
	scanf("%d", &s1.roll);

	printf("%s", "Enter student's mark: ");
	scanf("%lf", &s1.mark);

	puts("\nDisplaying student's information:");
	printf("Student's name: %s\nStudent's roll: %d\nStudent's mark: %.2lf\n", s1.name, s1.roll, s1.mark);

	return 0;
}
