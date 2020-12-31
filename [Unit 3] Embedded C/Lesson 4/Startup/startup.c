/* A basic startup file wriiten in C */
/* This is possible due to the fact that the Sp register can be set through the hardware */
/* Author: Abdelrahman Sultan */

#include <stdint.h>

extern int main(void);

void _reset(void);
void Default_Handler(void);

void NMI_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));
void HardFault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));
void MemManage_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));
void BusFault_Handler(void )__attribute__ ((weak, alias ("Default_Handler")));
void UsageFault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

/* stackTop will be used to define the address of the Sp register instead of a symbol from linker */
/* Just make sure to let it unintiallized so that it will be stored in the last region of ram which is the .bss section */
/* And here we had a random number of bytes which is 256 * sizeo of int = 1024 Bytes */
static uint32_t stackTop[256];

/* And here is just a different way to define the vector table using an array of pointer to functions instead of array of integers */
void (*const g_arrVectors[])(void) __attribute__((section(".vectors"))) = {

    (void (*)(void)) (&stackTop[0] + sizeof(stackTop)),
    _reset,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler
};

void _reset(void)
{
    /* Copy .data section from FLASH to SRAM */
    uint32_t dataSize = (uint8_t *)(& _edata) - (uint8_t *)(& _sdata);
    uint8_t *sdataROM = (uint8_t *)(& _etext);
    uint8_t *sdataRAM = (uint8_t *)(& _sdata);

    while(dataSize != 0)
    {
        *sdataRAM++ = *sdataROM++;
        dataSize--;
    }

    /* Initiallize .bss section */
    uint32_t bssSize = (uint8_t *)&(_ebss) - (uint8_t *)(& _sbss);
    uint8_t *sbssRAM = (uint8_t *)(& _sbss);

    while(bssSize != 0)
    {
        *sbssRAM++ = (uint8_t) 0;
        bssSize--;
    }
    
    /* Call main function */
    main();
}

void Default_Handler(void)
{
    _reset();
}
