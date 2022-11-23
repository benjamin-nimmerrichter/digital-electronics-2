#ifndef F_CPU
# define F_CPU 16000000 // CPU frequency in Hz required for delay funcs
#endif

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>     // AVR device-specific IO definitions
#include <util/delay.h> // Functions for busy-wait delay loops
#include <timer.h> 
#include <uart.h>
#include <gpio.h>
#include <avr/interrupt.h>
#include <stdlib.h> 
// -----
// This part is needed to use Arduino functions but also physical pin
// names. We are using Arduino-style just to simplify the first lab.
#define BTN 5    //PB5
#define X 0      //PC0
#define Y 1      //PC1
// -----
uint16_t xy_val[2]= {0,0};
//uint16_t adc_val=0;
/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle one LED and use delay library.
 * Returns:  none
 **********************************************************************/
int main(void)
{
  TIM1_overflow_interrupt_enable();
  TIM1_overflow_262ms();
  sei();

  uart_init(UART_BAUD_SELECT(9600, F_CPU));
  GPIO_mode_input_pullup(&DDRB,BTN);


  ADMUX &= ~(1<<REFS1); ADMUX |= (1<<REFS0);
  //ADMUX &= ~(1<<REFS1); ADMUX &= ~(1<<REFS0);
  // Select input channel ADC0 (voltage divider pin)
  
  // Enable ADC module
  ADCSRA |= (1<<ADEN);
  // Enable conversion complete interrupt
  ADCSRA |= (1<<ADIE);
    while(1)
    {

    }
    return 0;
}

  ISR(TIMER1_OVF_vect)
  {

    static uint8_t btn_val = 0;
    static uint8_t ovfs = 0;
    char str[4];

    btn_val = GPIO_read(&PINB,BTN);


  if (ovfs == 0){
    //for X
    ADMUX &= ~((1<<MUX0) | (1<<MUX1) | (1<<MUX2) | (1<<MUX3));
    ADCSRA |= (1<<ADSC);
    ovfs++;
    }
  else
  {
    //for y
    ADMUX &= ~( (1<<MUX1) | (1<<MUX2) | (1<<MUX3)); ADMUX &= ~(1<<MUX0);
    ADCSRA |= (1<<ADSC);

    ovfs = 0;
    }

    
    uart_puts("\r\nX: ");
    itoa(xy_val[0],str,10);
    uart_puts(str);
    uart_puts("\r\nY: ");
    itoa(xy_val[1],str,10);
    uart_puts(str);
    uart_puts("\r\nBTN: ");
    itoa(btn_val,str,10);
    uart_puts(str);    
    uart_puts("\r\n\r\n");
  }

  ISR(ADC_vect)
  {
    static uint8_t cycles = 0;
    if (cycles == 0)
    {
      xy_val[0] = ADC;
      cycles++;
    }
    else
    {
      xy_val[1] = ADC;
      cycles = 0;
    }
  }