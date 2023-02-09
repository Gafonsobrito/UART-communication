#include <avr/io.h> 
#include <avr/interrupt.h>
#include "UART.h"

char text[] = "Mensagem...\n"; // String que será enviadda pela UART

// Interrupção da UART
ISR (USART_RX_vect)
{
 char ch; // Armazena o caractere lido
 ch = UDR0; // Faz a leitura do buffer da serial
 
 // Converte letras minúsculas em maiúsculas
 if (ch>='a' && ch<='z')
 ch = ch - 'a' + 'A';
 
 // Converte letras maiúsculas em minúsculas
 else if (ch>='A' && ch <='Z')
 ch = ch - 'A' + 'a';
 
 // Envia para o computador
 UART_enviaCaractere(ch);
}
//------------------------------------------------------
int main()
{
 UART_config(); //Configura a comunicação serial
 UART_enviaString(text); //Envia a string armazenada no vetor s
 sei(); //Ativa as interrupções
 
while(1){ 
 } 
}
