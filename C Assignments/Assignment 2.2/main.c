/*
 * 	main.c
 *
 *  Created on: Aug 27, 2020
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

	char c;

	printf("Enter an alphabet: ");

	scanf("%c", &c);

	if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' \
			|| c == 'o' || c == 'O' || c == 'u' || c == 'U')
		printf("%c is a vowel.\n", c);

	else
		printf("%c is a constant.\n", c);

	return 0;
}
