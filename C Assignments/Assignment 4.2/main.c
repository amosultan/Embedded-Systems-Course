/*
 *  main.c
 *
 *  Calculate factorial of a number using recursion
 *
 *  Created on: Sep 9, 2020
 *  Author: Abdelrahman Sultan
 */


#include <stdio.h>

long long int factorial(int num);

int main(void)
{
	/* Usage of setvbuf() or fflush() functions is related to a well known console bug in eclipse
	 * when using a printf() function right before a scanf() function.
	 * For more info, checkout:
	 * https://bugs.eclipse.org/bugs/show_bug.cgi?id=173732
	 */

	setvbuf(stdout, NULL, _IONBF, 0);

	int num;
	long long int fact;

	do
	{
		puts("Enter a positive integer:");
		scanf("%d", &num);
	}
	while(num <= 0);

	fact = factorial(num);

	printf("Factorial of %d = %lld", num, fact);

	return 0;
}

long long int factorial(int num)
{
	if (num == 1 || num == 0)
		return 1;
	else
		return num * factorial(num - 1);
}
