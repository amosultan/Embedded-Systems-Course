/*
 *  main.c
 *
 *  Created on: Sep 8, 2020
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

	int arr[100], element;
	size_t i, nElements, location;

	printf("Enter number of elements: ");
	scanf("%u", &nElements);

	for(i = 0; i < nElements; i++)
		scanf("%d", &arr[i]);

	printf("Enter the element to be inserted: ");
	scanf("%d", &element);

	do
	{
		printf("Enter the location: ");
		scanf("%u", &location);
	}
	while (location <= 0);

	for (i = nElements; i >= location; i--)
		arr[i] = arr[i - 1];

	arr[i] = element;

	for(i = 0; i <= nElements; i++)
		printf("%d ", arr[i]);

	puts("");

	return 0;
}
