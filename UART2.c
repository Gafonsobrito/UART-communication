#include <avr/io.h> 
#include <avr/interrupt.h>
#include "UART.h"

char text[] = "Mensagem...\n"; // String que ser� enviadda pela UART

// Interrup��o da UART
ISR (USART_RX_vect)
{
 char ch; // Armazena o caractere lido
 ch = UDR0; // Faz a leitura do buffer da serial
 
 // Converte letras min�sculas em mai�sculas
 if (ch>='a' && ch<='z')
 ch = ch - 'a' + 'A';
 
 // Converte letras mai�sculas em min�sculas
 else if (ch>='A' && ch <='Z')
 ch = ch - 'A' + 'a';
 
 // Envia para o computador
 UART_enviaCaractere(ch);
}
//------------------------------------------------------
int main()
{
 UART_config(); //Configura a comunica��o serial
 UART_enviaString(text); //Envia a string armazenada no vetor s
 sei(); //Ativa as interrup��es
 
while(1){ 
 } 
}
