/*
 *  main.c
 *
 *  C program to calculate the power of a number using recursion
 *
 *  Created on: Sep 9, 2020
 *  Author: Abdelrahman Sultan
 */


#include <stdio.h>

long long int numPow(int base, int power);

int main(void)
{
	/* Usage of setvbuf() or fflush() functions is related to a well known console bug in eclipse
	 * when using a printf() function right before a scanf() function.
	 * For more info, checkout:
	 * https://bugs.eclipse.org/bugs/show_bug.cgi?id=173732
	 */

	setvbuf(stdout, NULL, _IONBF, 0);

	int base, power;
	long long int res;

	puts("Enter base number:");
	scanf("%d", &base);

	puts("Enter power number:");
	scanf("%d", &power);

	res = numPow(base, power);

	if (base < 0 && power == 0)
		res = -res;

	printf("%d^%d = %lld", base, power, res);

	return 0;
}

long long int numPow(int base, int power)
{
	if(power > 0)
		return base * numPow(base, power - 1);
	else
		return 1;
}
