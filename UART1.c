#include <avr/interrupt.h>
#include <avr/io.h>

// Interrup��o
ISR(USART_RX_vect){
    
    char data = 0;
    data = UDR0; // Faz a leitura do valor, UDR0 � de recep��o
    UDR0 = data; // Envia a informa��o, UDR0 � de transmiss�o
}

int main(void) {
    
    // Configura��o dos registradores
    UBRR0 = 103; // Configura Baud rate como 9600bps
    UCSR0B = 0b10011000; // Habilita a interrup��o de recep��o e os pinos RX/TX
    UCSR0C = 0b00000110; // Configura como ass�ncro e 8 bits de dado
    
    sei();
    
    while (1) {
    }
}
