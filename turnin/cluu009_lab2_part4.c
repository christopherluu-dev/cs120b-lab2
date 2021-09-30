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
    DDRB = 0x00; PORTB = 0xFF; //Configure port B's pins as output
    DDRC = 0x00; PORTC = 0xFF;
    DDRD = 0xFF; PORTD = 0x00;

    unsigned char tmpA = PINA;
    unsigned char tmpB = PINB;
    unsigned char tmpC = PINC;
    unsigned char totalWeight;

    while (1) {
        totalWeight = tmpA + tmpB + tmpC;
        PORTD = (totalWeight > 140) ? 0x01 : 0x00;
        if((tmpA > tmpC) && ((tmpA-tmpC) > 80)){
            PORTD = PORTD | 0x02;
        }
        else if ((tmpC > tmpA) && ((tmpC-tmpA > 80)){
            PORTD = PORTD | 0x02;
        }
        else if ((tmpA == tmpC){
            PORTD = PORTD | 0x00;    
        }

        PORTD = PORTD | ((totalWeight >> 2) << 4);
    }
    return 0;
}
