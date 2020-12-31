/* A basic linker script for the arm cortex m4 basde microcontrollers */
/*Author: Abdelrahman Sultan */

ENTRY(_reset)

MEMORY
{
    FLASH (RX): ORIGIN = 0x00000000, LENGTH = 256K
    SRAM (RWX): ORIGIN = 0x20000000, LENGTH = 32K
}

SECTIONS
{
    .text :
    {
        . = ALIGN(4);
        
        *(.vectors*)
        *(.text*)
        *(.rodata*)
        
        . = ALIGN(4);
        
        _etext = .;     /* End of text section at ROM and start of data section at ROM */
    
    }> FLASH

    .data :
    {
        . = ALIGN(4);

        _sdata = .;     /* Start of data section at RAM */

        *(.data)

        . = ALIGN(4);

        _edata = .;     /* End of data Section at RAM */

    }> SRAM AT> FLASH

    .bss :
    {
        . = ALIGN(4);

        _sbss = .;      /* Start of bss section at RAM */

        *(.bss)

        . = ALIGN(4);

        _ebss = .;      /* End of bss section at RAM */

    }> SRAM
}