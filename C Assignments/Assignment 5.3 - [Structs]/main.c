/*
 *  File Name: main.c
 *  Description: Write a C program to add two complex numbers through a user defined function.
 *  
 *  Created on: Nov 9, 2020
 *  Author: Abdelrahman Sultan
 */


#include <stdio.h>

struct complex
{
	double real;
	double imaginary;
};

void addComplex(const struct complex *const num1, const struct complex *const num2);

int main(void)
{
	/* Usage of setvbuf() or fflush() functions is related to a well known console bug in eclipse
	 * when using a printf() function right before a scanf() function.
	 * For more info, checkout:
	 * https://bugs.eclipse.org/bugs/show_bug.cgi?id=173732
	 */

	setvbuf(stdout, NULL, _IONBF, 0);

	struct complex num1, num2;

	puts("First complex number:");

	printf("%s", "Enter real and imaginary parts respectively: ");
	scanf("%lf%lf", &num1.real, &num1.imaginary);

	puts("Second complex number:");
	printf("%s", "Enter real and imaginary parts respectively: ");
	scanf("%lf%lf", &num2.real, &num2.imaginary);

	addComplex(&num1, &num2);
	return 0;
}

void addComplex(const struct complex *const num1, const struct complex *const num2)
{
	printf("Sum = %.2lf + %.2lfi", num1->real + num2->real, num1->imaginary + num2->imaginary);
}
