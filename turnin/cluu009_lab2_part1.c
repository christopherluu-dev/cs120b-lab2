/*	Author: christopherluu
 *  Partner(s) Name: 
 *	Lab Section: 22 
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; //Configure port A's pins as input
    DDRB = 0xFF; PORTB = 0x00; //Configure port B's pins as output
    
    unsigned char tmpA0 = 0x00;
    unsigned char tmpA1 = 0x00;
    unsigned char tmpB = 0x00;

    while (1) {
        tmpA0 = PINA & 0x01;
        tmpA1 = (PINA & 0x02) >> 1;
        
        if (tmpA0 == 0x01 && tmpA1 == 0x00) { 
            tmpB = 0x01;
        }
        else{
            tmpB = 0x00;
        }
        PORTB = tmpB;
    }
    return 0;
}
