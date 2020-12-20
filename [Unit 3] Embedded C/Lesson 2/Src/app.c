#include "uart.h"

unsigned char buffer[100] = "Learn-in-depth: Abdelrahman";

int main(void)
{
	uartSendString(buffer);
	
	return 0;
}