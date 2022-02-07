// Copyright 2019 Ruben Suarez

#include <avr/io.h>
#include <util/delay.h>

//--- PIN Assignments ----------------------------------------------------
#define RED_PIN             0
#define GREEN_PIN           5
#define BLUE_PIN            4

//--- PIN Controls -------------------------------------------------------
#define RED_ON              (PORTB |= (1<<RED_PIN))
#define RED_OFF             (PORTB &= ~(1<<RED_PIN))
#define GREEN_ON            (PORTB |= (1<<GREEN_PIN))
#define GREEN_OFF           (PORTB &= ~(1<<GREEN_PIN))
#define BLUE_ON             (PORTB |= (1<<BLUE_PIN))
#define BLUE_OFF            (PORTB &= (0X01))

//--- Device Setup -------------------------------------------------------
#define OUTPUT_CONFIG       (DDRB |= (1<<RED_PIN) | (1<<GREEN_PIN) | (1<<BLUE_PIN))
#define CPU_PRESCALE(n)     (CLKPR = 0x80, CLKPR = (n))

//--- LED ----------------------------------------------------------------
void LEDColor(int distance) {

   if (distance > 400) {
	BLUE_ON;
   }
   if (distance < 10) {
      	RED_ON;
   }
   else {
      	GREEN_ON;
   }
}

//--- Main ----------------------------------------------------------
int main(void) {
   OUTPUT_CONFIG;
   int distance;

   //--- Main Loop ------------------------------------------------------
   while(1){
	BLUE_OFF;
   	GREEN_OFF;
   	RED_OFF;
      	distance = sonar();
    	LEDColor(distance);
   }
   return 0;
}

