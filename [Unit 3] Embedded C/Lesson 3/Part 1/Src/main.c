/**
 ********************************************************************************************
 * @file           : main.c
 * @author         : Abdelrahman Sulan
 * @brief          : Toggling an LED with an arbitrary delay using STM32F103C6 uController.
 ********************************************************************************************
 */

#include "platform_types.h"

#define RCC_BASE    0x40021000  /*RCC register base address*/
#define PORTA_BASE  0x40010800  /*PORTA register base address*/

#define RCC_APB2ENR *((vuint32 *) (RCC_BASE + 0x18))
#define GPIOA_CRH   *((vuint32 *) (PORTA_BASE + 0x04))
#define GPIOA_ODR   *((vuint32 *) (PORTA_BASE + 0x0C))

typedef union GPIO
{
    vuint32 port;

    struct PIN
    {
        vuint32 reserved:13;
        vuint32 pin13:1;
    } pin;
} R_ODR_t;

volatile R_ODR_t *ODR = (volatile R_ODR_t *) (PORTA_BASE + 0x0C);

int main(void)
{
    RCC_APB2ENR |= (1 << 2);
    GPIOA_CRH &= 0xFF0FFFFF;
    GPIOA_CRH |= 0x00200000;

    vuint32 i;

    while(1)
    {
        /*Toggle pin 13 of port A*/
        ODR->pin.pin13 ^= 1;

        /*Arbitrary delay*/
        for(i = 0; i < 500000; i++);
    }

    return 0;
}
