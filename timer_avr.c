/* 
 * File:   main.c
 * Author: L03038590
 *
 * Created on 9 de febrero de 2022, 08:38 PM
 */

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include<avr/interrupt.h>
int time_count;
int bandera = 0;
int nota = 0;
int flag = 0;

void varDelay(float time) {
    while(time>0) {
        time--;
        _delay_ms(1);
    }
}

void pausa(float time) {
    PORTB = 0x00; /*complement port bit to blink LED*/
    time_count = 0; /*reset time counter for next .5 second*/
    bandera = 0;
    varDelay(time);
}

ISR (TIMER0_OVF_vect) 
{
    TCNT0 = 96; /*set for 10 us timeout*/
    TIFR0 = 1<<TOV0;
    ++time_count;

    if (time_count == nota && bandera == 0)
    {
        PORTB = 0x01; /*complement port bit to blink LED*/
        time_count = 0; /*reset time counter for next .5 second*/
        bandera = 1;
    }
    if (time_count == nota && bandera == 1)
    {
        PORTB = 0x00; /*complement port bit to blink LED*/
        time_count = 0; /*reset time counter for next .5 second*/
        bandera = 0;
    }
}

int main(void) {
    DDRC = 0x00;
    DDRB = 0xFF;
    TCCR0B = 0x01;
    TCNT0=0x00;
    TIFR0 = 1<<TOV0;
    TIMSK0 = 1<<TOIE0;
    

    sei();
    while(1){
        //Star wars tema muy lento
        nota = 0;  //RE
        pausa(1000);

        nota = 34;  //RE
        pausa(600);

        nota = 0;  //SILENCIO
        pausa(200);

        nota = 34;  //RE
        pausa(600);

        nota = 0;  //SILENCIO
        pausa(200);

        nota = 34;  //RE
        pausa(600);

        nota = 25;  //SOL
        pausa(1500);

        nota = 17;  //RE
        pausa(1500);     

        nota = 19;  //DO
        pausa(1000);

        nota = 20;  //SI
        pausa(1200);

        nota = 22;  //LA
        pausa(1000);

        nota = 12;  //SOL
        pausa(1600);

        nota = 17;  //RE
        pausa(1200);

        nota = 19;  //DO
        pausa(1000);

        nota = 20;  //SI
        pausa(1200);

        nota = 22;  //LA
        pausa(1000);

        nota = 12;  //SOL
        pausa(1600);

        nota = 17;  //RE
        pausa(1200);

        nota = 19;  //DO
        pausa(1000);

        nota = 20;  //SI
        pausa(1400);

        nota = 19;  //DO
        pausa(1200);

        nota = 22;  //LA
        pausa(1600);

        nota = 0;
        pausa(500);
        
        //Star wars tema lento
        nota = 0;  //RE
        pausa(1000);

        nota = 34;  //RE
        pausa(300);

        nota = 0;  //SILENCIO
        pausa(100);

        nota = 34;  //RE
        pausa(300);

        nota = 0;  //SILENCIO
        pausa(100);

        nota = 34;  //RE
        pausa(300);

        nota = 25;  //SOL
        pausa(750);

        nota = 17;  //RE
        pausa(750);     

        nota = 19;  //DO
        pausa(500);

        nota = 20;  //SI
        pausa(600);

        nota = 22;  //LA
        pausa(500);

        nota = 12;  //SOL
        pausa(800);

        nota = 17;  //RE
        pausa(600);

        nota = 19;  //DO
        pausa(500);

        nota = 20;  //SI
        pausa(600);

        nota = 22;  //LA
        pausa(500);

        nota = 12;  //SOL
        pausa(800);

        nota = 17;  //RE
        pausa(600);

        nota = 19;  //DO
        pausa(500);

        nota = 20;  //SI
        pausa(700);

        nota = 19;  //DO
        pausa(600);

        nota = 22;  //LA
        pausa(800);

        nota = 0;
        pausa(500);
        
        //Star wars tema rapido
        nota = 0;  //RE
        pausa(1000);

        nota = 34;  //RE
        pausa(150);

        nota = 0;  //SILENCIO
        pausa(50);

        nota = 34;  //RE
        pausa(150);

        nota = 0;  //SILENCIO
        pausa(50);

        nota = 34;  //RE
        pausa(150);

        nota = 25;  //SOL
        pausa(380);

        nota = 17;  //RE
        pausa(380);     

        nota = 19;  //DO
        pausa(250);

        nota = 20;  //SI
        pausa(300);

        nota = 22;  //LA
        pausa(250);

        nota = 12;  //SOL
        pausa(400);

        nota = 17;  //RE
        pausa(300);

        nota = 19;  //DO
        pausa(250);

        nota = 20;  //SI
        pausa(300);

        nota = 22;  //LA
        pausa(250);

        nota = 12;  //SOL
        pausa(400);

        nota = 17;  //RE
        pausa(300);

        nota = 19;  //DO
        pausa(250);

        nota = 20;  //SI
        pausa(350);

        nota = 19;  //DO
        pausa(300);

        nota = 22;  //LA
        pausa(400);

        nota = 0;
        pausa(500);
    }   
}

