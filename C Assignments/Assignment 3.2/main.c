/*
 *  main.c
 *
 *  Created on: Sep 6, 2020
 *  Author: Abdelrahman Sultan
 */


#include <stdio.h>

int main(void)
{
	/* Usage of setvbuf() or fflush() functions is related to a well known console bug in eclipse
	 * when using a printf() function right before a scanf() function.
	 * For more info, checkout:
	 * https://bugs.eclipse.org/bugs/show_bug.cgi?id=173732
	 */

	setvbuf(stdout, NULL, _IONBF, 0);

	int n;
	size_t i;

	do
	{
		printf("Enter the numbers of data: ");
		scanf("%d", &n);
	}
	while (n <= 0);

	float arr[n], sum = 0.0;

	for(i = 1; i <= n; i++)
	{
		printf("%u. Enter number: ", i);
		scanf("%f", &arr[i-1]);
		sum += arr[i-1];
	}

	printf("Average = %.2f\n", sum/n);

	return 0;
}
