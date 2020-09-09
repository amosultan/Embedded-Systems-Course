/*
 *  main.c
 *
 *  Find prime numbers between two integers.
 *
 *  Created on: Sep 9, 2020
 *  Author: Abdelrahman Sultan
 */


#include <stdio.h>

void primeNumbers(int a, int b);

int main(void)
{
	/* Usage of setvbuf() or fflush() functions is related to a well known console bug in eclipse
	 * when using a printf() function right before a scanf() function.
	 * For more info, checkout:
	 * https://bugs.eclipse.org/bugs/show_bug.cgi?id=173732
	 */

	setvbuf(stdout, NULL, _IONBF, 0);

	int x, y;

	puts("Enter two numbers intervals:");
	scanf("%d %d", &x, &y);

	primeNumbers(x, y);

	return 0;
}

void primeNumbers(int a, int b)
{
	size_t i, j, flag;

	printf("Prime numbers between %d and %d are: ", a, b);

	for(i = a; i <= b; i++)
	{
		if (i == 0 || i == 1)
			continue;

		flag = 0;

		for(j = 2; j <= i/2; j++)
			if(i % j == 0)
			{
				flag = 1;
				break;
			}

		if (flag == 0)
			printf("%d ", i);
	}
}
