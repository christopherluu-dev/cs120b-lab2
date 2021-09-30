/*	Author: christopherluu
 *  Partner(s) Name: 
 *	Lab Section: 22 
 *	Assignment: Lab #2  Exercise #2
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
    PORTC = 0x00;

    unsigned char tmpA0 = 0x00;
    unsigned char tmpA1 = 0x00;
    unsigned char tmpA2 = 0x00;
    unsigned char tmpA3 = 0x00;
    unsigned char cntavail;

    while (1) {
        tmpA0 = PINA & 0x01;
        tmpA1 = (PINA & 0x02) >> 1;
        tmpA2 = (PINA & 0x04) >> 2;
        tmpA3 = (PINA & 0x08) >> 3;
        
        cntavail = 4 - (tmpA0 + tmpA1 + tmpA2 + tmpA3);
        PORTC = cntavail;
        if(cntavail == 0){
            PORTC = 0x80 | cntavail;
        }
    }
    return 0;
}
