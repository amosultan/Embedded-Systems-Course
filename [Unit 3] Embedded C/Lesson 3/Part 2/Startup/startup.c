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
extern uint32_t _stack_top;

uint32_t vectors[] __attribute__((section(".vectors"))) = {

    (uint32_t) &_stack_top,
    (uint32_t) _reset,
    (uint32_t) NMI_Handler,
    (uint32_t) HardFault_Handler,
    (uint32_t) MemManage_Handler,
    (uint32_t) BusFault_Handler,
    (uint32_t) UsageFault_Handler
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
