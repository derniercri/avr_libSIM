#ifndef SERIE_H
#define SERIE_H


// structure de configuration du port serie
typedef struct 
{
  unsigned char vitesse;
  char reception;
  char transmission;
  char interuptionT;
  char interuptionR;
} serie_configuration;

//initialise le port serie grace aux valeur de la structure de configuration
void serie_init(serie_configuration configuration);

// transmet un octet 
void serie_transmetre(char data);

// Se met en attente d'un octet en entrée du port serie
unsigned char serie_recevoir(void);

//transmet une suite d'octet
void serie_transmetre_chaine(const char *s);

#endif 
