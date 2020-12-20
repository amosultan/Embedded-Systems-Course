#include "uart.h"

void uartSendString(const unsigned char *const string)
{
	int i = 0;

	while (*(string + i) != '\0')
	{
		UART0DR = *(string + i);

		i++;
	}
}