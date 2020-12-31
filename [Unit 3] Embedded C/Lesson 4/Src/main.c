/**
 ********************************************************************************************
 * @file           : main.c
 * @author         : Abdelrahman Sulan
 * @brief          : Toggling an LED with an arbitrary delay using STM32F103C6 uController.
 ********************************************************************************************
 */

#include "platform_types.h"

#define SYSCTL_BASE   0x400FE000  /*SYSCTL register base address*/
#define PORTF_BASE    0x40025000  /*PORTF register base address*/

#define SYSCTL_RCGC2_R      *((vuint32 *) (SYSCTL_BASE + 0x108))
#define GPIOA_PORTF_DIR_R   *((vuint32 *) (PORTF_BASE + 0x400))
#define GPIO_PORTF_DEN_R    *((vuint32 *) (PORTF_BASE + 0x51C))

typedef union GPIO
{
    vuint32 port;

    struct PIN
    {
        vuint32 reserved:3;
        vuint32 pin3:1;
    } pin;
} R_ODR_t;

volatile R_ODR_t *ODR = (volatile R_ODR_t *) (PORTF_BASE + 0x3FC);

int main(void)
{
		vuint32 i;

    SYSCTL_RCGC2_R = 0x20;
	
		for(i = 0; i < 200; i++);
    
		GPIOA_PORTF_DIR_R |= 1 << 3;
    GPIO_PORTF_DEN_R |= 1 << 3;
    while(1)
    {
        /*Toggle pin 13 of port A*/
        ODR->pin.pin3 ^= 1;

        /*Arbitrary delay*/
        for(i = 0; i < 500000; i++);
    }

    return 0;
}