//Exemple d'utilisation de serie.h


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "serie.h"
#include <avr/interrupt.h>

#define VITESSE 103 // 9600 bauds à 16 MHz
#define RECEPTION 1
#define TRANSMISSION 1
#define INTERUPTIONT 0
#define INTERUPTIONR 0


ISR(USART_RX_vect)
{
  PORTB ^= 0x03;
  _delay_ms(10000);
}

void main()
{
  //creation de la structure de configuration de l'interface Série
  serie_configuration configuration;
  configuration.vitesse = VITESSE;
  configuration.reception = RECEPTION;
  configuration.transmission = TRANSMISSION;
  configuration.interuptionT = INTERUPTIONT;
  configuration.interuptionR = INTERUPTIONR;

  //configuration des PINS
  DDRB = 0x03;
  PORTB = 0x03;

  //initialisation de la liaison série
  serie_init(configuration);

  //transmission d'une chaine
  serie_transmetre_chaine("test_serie");

  //attente de reception
  while(1){
    if(serie_recevoir())
    PORTB ^= 0x03;
  }
}
