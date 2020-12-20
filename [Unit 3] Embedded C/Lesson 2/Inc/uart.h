#ifndef _UART_H_
#define _UART_H_

#define UART0DR *((volatile unsigned int *const) (0x101f1000))

void uartSendString(const unsigned char *const string);

#endif /*_UART_H_*/