#include <avr/interrupt.h>
#include <avr/io.h>

// Interrupção
ISR(USART_RX_vect){
    
    char data = 0;
    data = UDR0; // Faz a leitura do valor, UDR0 é de recepção
    UDR0 = data; // Envia a informação, UDR0 é de transmissão
}

int main(void) {
    
    // Configuração dos registradores
    UBRR0 = 103; // Configura Baud rate como 9600bps
    UCSR0B = 0b10011000; // Habilita a interrupção de recepção e os pinos RX/TX
    UCSR0C = 0b00000110; // Configura como assíncro e 8 bits de dado
    
    sei();
    
    while (1) {
    }
}
