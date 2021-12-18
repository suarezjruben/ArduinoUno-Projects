#include "config.h"
//Loading Liquid Crystal Library
#include <LiquidCrystal.h> 

//Creating Liquid Crystal Object called LCD
//11, 9, 2, 3, 4, 5 are the pins on arduino for the rs, rw enable and d4-d7 pins on the lcd
LiquidCrystal LCD(11, 9, 2, 3, 4, 5);

dummy: 	.byte 0		; dummy global variable

        .section .text
        .global     main
        .extern     delay          
        .org        0x0000

main:
	; clear the SREG register
        eor     r1, r1                     ; cheap zero
        out     _(SREG), r1                ; clear flag register

        ; set up the stack
        ldi         r28, (RAMEND & 0x00ff)
        ldi         r29, (RAMEND >> 8)
        out         _(SPH), r29
        out         _(SPL), r28

	; initialize the CPU clock to run at full speed
	ldi         r24, 0x80
        sts         CLKPR, r24              ; allow access to clock setup
        sts         CLKPR, r1               ; run at full speed

        ; set up the sensor ports

measure:

delay:


