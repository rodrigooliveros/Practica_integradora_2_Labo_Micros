#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include<avr/interrupt.h>
int time_count;
int bandera = 0;
int nota;

int main(void) {
    cli();
    DDRB = 0b00001000;
    PORTB &= ~(1<<0)|(1<<1)|(1<<2);
    TCCR0B = 0x01; //Prescaler en 8
    TCNT0=96; 
    TIFR0 = 1<<TOV0; //Ajustamos el Timer0 con la bandera de interrupción
    TIMSK0 = 1<<TOIE0; //Activamos la interrupción por Overflow
    sei();
    while(1){
        if(PINB0 == 1){
        G3();
        _delay_ms(400);
        A3();
        _delay_ms(400);
        G4();
        _delay_ms(400);
        E4();
        _delay_ms(1000);
        silencio();
        _delay_ms(200);
        E4();
        _delay_ms(300);
        F4();
        _delay_ms(300);
        G4();
        _delay_ms(300);
        A4();
        _delay_ms(500);
        Bb4();
        _delay_ms(500);
        A4();
        _delay_ms(500);
        G4();
        _delay_ms(500);       
        F4();
        _delay_ms(1000);
        silencio();
        _delay_ms(100);
        F4();
        _delay_ms(500); 
        E4();
        _delay_ms(500);
        F4();
        _delay_ms(800);
        silencio();
        _delay_ms(1000);
        D4();
        _delay_ms(500);
        E4();
        _delay_ms(500);
        F4();
        _delay_ms(1000);
        //
        D4();
        _delay_ms(300);
        E4();
        _delay_ms(300);
        F4();
        _delay_ms(500);
        G4();
        _delay_ms(600);
        Ab4();
        _delay_ms(600);
        G4();
        _delay_ms(500);
        F4();
        _delay_ms(500);       
        E4();
        _delay_ms(1000);
        silencio();
        _delay_ms(100);
        F4();
        _delay_ms(500); 
        E4();
        _delay_ms(1000);
         D4();
        _delay_ms(300);
        }
        
        //Up theme
        else if(PINB1 == 1){
        F4();
        _delay_ms(200);
        A4();
        _delay_ms(200);
        F4();
        _delay_ms(200);
        E4();
        _delay_ms(1000);
        silencio();
        _delay_ms(500);
        F4();
        _delay_ms(200);
        A4();
        _delay_ms(200);
        E4();
        _delay_ms(200);
        D4();
        _delay_ms(400);
        silencio();
        _delay_ms(300);
        D4();
        _delay_ms(200);
        F4();
        _delay_ms(200);
        D4();
        _delay_ms(200);
        C4();
        _delay_ms(1000);
        silencio();
        _delay_ms(500);
        D4();
        _delay_ms(200);
        A4();
        _delay_ms(400);
        G4();
        _delay_ms(400);
        silencio();
        _delay_ms(300);
        D4();
        _delay_ms(300);
        A4();
        _delay_ms(500);
        G4();
        _delay_ms(500);
        F4();
        _delay_ms(500);
        E4();
        _delay_ms(1000);
        }
        //Mi corazón encantado
        else if(PINB2 == 1){
        Bb4();
        _delay_ms(300);
        G4();
        _delay_ms(150);
        F4();
        _delay_ms(150);
        Eb4();
        _delay_ms(300);
        F4();
        _delay_ms(150);
        G4();
        _delay_ms(150);
        Bb4();
        _delay_ms(300);
        G4();
        _delay_ms(150);
        F4();
        _delay_ms(150);
        Eb4();
        _delay_ms(400);
         Bb4();
        _delay_ms(300);
        G4();
        _delay_ms(150);
        F4();
        _delay_ms(150);
        Eb4();
        _delay_ms(300);
        F4();
        _delay_ms(150);
        G4();
        _delay_ms(150);
        C4();
        _delay_ms(500);
        silencio();
        _delay_ms(150);
        Bb4();
        _delay_ms(300);
        G4();
        _delay_ms(150);
        F4();
        _delay_ms(150);
        Eb4();
        _delay_ms(300);
        F4();
        _delay_ms(150);
        G4();
        _delay_ms(150);
        Bb4();
        _delay_ms(300);
        G4();
        _delay_ms(150);
        F4();
        _delay_ms(150);
        Eb4();
        _delay_ms(400);
        }
    }
}

ISR (TIMER0_OVF_vect) {

    TCNT0 = 96; /*set for 10 us timeout*/
    TIFR0 = 1<<TOV0;
    ++time_count;
    if (time_count == nota && bandera == 0)
    {
    PORTB |= (1<<PINB3); 
    time_count = 0; 
    bandera = 1;
    }
    if (time_count == nota && bandera == 1)
    {
    PORTB &= ~(1<<PINB3); 
    time_count = 0; 
    bandera = 0;
    }
}

//C3-B3
void C3(){
    return nota = 77;
}
void D3(){
    return nota = 68;
}
void E3(){
    return nota = 61;
}
void F3(){
    return nota = 57;
}
void G3(){
    return nota = 51;
}
void A3(){
    return nota = 46;
}
void B3(){
    return nota = 41;
}
//C4-B4
void C4(){
    return nota = 38;
}
void D4(){
    return nota = 34;
}
void Eb4(){
    return nota = 32;
}
void E4(){
    return nota = 30;
}
void F4(){
    return nota = 29;
}
void G4(){
    return nota = 26;
}
void Ab4(){
    return nota = 24;
}
void A4(){
    return nota = 23;
}
void Bb4(){
    return nota = 22;
}
void B4(){
    return nota = 20;
}
//C5-B5
void C5(){
    return nota = 19;
}
void D5(){
    return nota = 17;
}
void E5(){
    return nota = 15;
}
void F5(){
    return nota = 14;
}
void G5(){
    return nota = 13;
}
void A5(){
    return nota = 12;
}
void Bb5(){
    return nota = 11;
}
void B5(){
    return nota = 10;
}
silencio(){
    return nota = 0;
}