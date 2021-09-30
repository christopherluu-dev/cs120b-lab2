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

    unsigned char tmpA;
    unsigned char tmpB;
    unsigned char tmpC;
    unsigned char tmpD;
    unsigned char totalWeight;

    while (1) {
        tmpA = PINA;
        tmpB = PINB;
        tmpC = PINC;
        tmpD = 0x00;
        totalWeight = tmpA + tmpB + tmpC;
        
        if(totalWeight > 140){
            tmpD = tmpD | 0x01;
        }
        else{
            tmpD = tmpD & 0x00;
        }
        
        if((tmpA - tmpC) > 80){
            tmpD = tmpD | 0x02;
        }
        else if((tmpC - tmpA) > 80){
            tmpD = tmpD | 0x02;
        }
        else{
            tmpD = tmpD & 0x01;
        }

        tmpD = tmpD | ((totalWeight >> 2) & 0xFC);
        PORTD = tmpD;

    }
    return 0;
}
