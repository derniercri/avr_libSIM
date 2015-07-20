#include <avr/io.h>
#include <avr/pgmspace.h>

#include "serie.h"


void serie_init(serie_configuration configuration)
{
  UBRR0L =configuration.vitesse;
  if(configuration.reception)
    UCSR0B |= (1 << TXEN0);
  if(configuration.transmission)
    UCSR0B |= (1 << RXEN0); 
  if(configuration.interuptionT)
    UCSR0B |= (1 << TXCIE0);
  if(configuration.interuptionR)
    UCSR0B |= (1 << RXCIE0);

  //configuration de la taille des donnés transmises à 8 bits
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void serie_transmetre (char data)
{
  //  while(UDRE0 != 1);
  loop_until_bit_is_set(UCSR0A,UDRE0);
  UDR0 = data;
}

unsigned char serie_recevoir(void)
{
  //  while(RXC0 != 1);
  loop_until_bit_is_set(UCSR0A,RXC0);
  return 1;
}

void serie_transmetre_chaine(const char *s)
{
  int i;
  for(i = 0; s[i] != 0; i++)
    serie_transmetre(s[i]);
  serie_transmetre(13);
}
