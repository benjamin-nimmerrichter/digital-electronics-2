#ifndef F_CPU
#define F_CPU 16000000 // CPU frequency in Hz required for delay funcs
#endif

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>     // AVR device-specific IO definitions
//#include <util/delay.h> // Functions for busy-wait delay loops
#include <timer.h> 
//#include <uart.h>
#include <gpio.h>
#include <avr/interrupt.h>
#include <stdlib.h> 

// -----
// This part is needed to use Arduino functions but also physical pin
// names. We are using Arduino-style just to simplify the first lab.
#define OFFSET 128
#define CONST 0.70556
uint8_t duty0 = 128;
uint8_t duty1 = 128;
uint8_t degrees = 0;
int8_t i;
int8_t ovfs = 0;


int main(void)
{
  SREG |= (1<<7);
  //set WGM to fast PWM (mode 7)
  TCCR1B |= (1<<CS11) | (1<<CS10);
  //duty cycle
  OCR1A = 0x80;
  OCR1B = 0x20;
  //set COM0A and COM0B to 1 for fast PWM output
  TCCR1A |= (1<<COM1A1) | (1<<COM1B1) | (1<<WGM10) | (1<<WGM11)| (1<<WGM12); TCCR1A &=~((1<<COM1A0) | (1<<COM1B0) | (1<<WGM13));
  //OCR0B = 0x80;
  DDRB |= (1<<1)|(1<<2); 
  TIM0_overflow_interrupt_enable();
  TIM0_overflow_4s();
  sei();

  while (1)
  {

  }
  return 0;
}

ISR(TIMER0_OVF_vect)
{
  if(ovfs >= 5)
  {
  if (degrees>=127)
  {
    i = -1;
  }
  if (degrees==0)
  {
    i = +1;
  }


  duty0 = (uint8_t)(((double)OFFSET)+(CONST*((double)degrees)));
  OCR1A = degrees;
  OCR1B = 127-degrees;

  degrees = degrees+i;
  ovfs=0;
  }
  ovfs++;

}
 