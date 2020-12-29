/* An initial and very basic startup code for arm cortex-m3 based controllers */

.global _reset

/* 
 * To ensure that some instructions will be placed in an appropriate section,
 * we use the assembler commmand .section followed by the name of the section
 */

.section .vectors

/* SRAM starts at 0x2000 0000 */
/* Sp register address is SRAM starting address + 0x1000*/
/* The value of first address in falsh is the first address which the Sp register shall have */ 

.word 0x20001000             /* Stack top address */
.word _reset                /* Reset_Handler */
.word Vector_Handler        /* NMI_Handler */
.word Vector_Handler        /* HardFault_Handler */
.word Vector_Handler        /* MemManage_Handler */
.word Vector_Handler        /* BusFault_Handler */
.word Vector_Handler        /* UsageFault_Handler */
.word Vector_Handler        /* Reserved */
.word Vector_Handler        /* Reserved */
.word Vector_Handler        /* Reserved */
.word Vector_Handler        /* Reserved */
.word Vector_Handler        /* SVC_Handler */
.word Vector_Handler        /* DebugMon_Handler */
.word Vector_Handler        /* Reserved */
.word Vector_Handler        /* PendSV_Handler */
.word Vector_Handler        /* SysTick_Handler */

.section .text

_reset:
    bl main
    b .

/* This directive specifies that the following symbol is the name of a Thumb encoded function. */
.thumb_func

Vector_Handler:
    bl _reset
