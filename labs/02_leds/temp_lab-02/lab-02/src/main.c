
#ifndef F_CPU
# define F_CPU 16000000 // CPU frequency in Hz required for delay funcs
#endif

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>     // AVR device-specific IO definitions
#include <util/delay.h> // Functions for busy-wait delay loops
#include <gpio.h>


int main(void)
{
    uint8_t temp = 0;
    GPIO_mode_output(&DDRB, 5);  // Set output mode in DDRB reg
    GPIO_mode_input_pullup(&DDRD, 6);  // Set output mode in DDRB reg
    while (1)
    {
    // Examples of various function calls
    temp = GPIO_read(&PIND,6);
    if (temp == 0)
    {
        GPIO_write_toggle(&DDRB, 5);
        _delay_ms(400);
    }//temp = GPIO_read(&PIND, BTN);
    
    }

    // Will never reach this
    return 0;
}