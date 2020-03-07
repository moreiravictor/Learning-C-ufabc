#include <stdio.h>
#include <stdlib.h>

typedef struct country_s {
  char sigla[3];
  double populacao;
} country;

void imprime (country c) {
  printf("%s %.1f\n", c.sigla, c.populacao);
}

void muda(country *brasil, country *argentina) {
  country *c = malloc(sizeof(country)); 
  *c = *brasil;
  *brasil = *argentina;
  *argentina = *c;
  
}

int main(void) {
  country brasil = {"BRA", 209.3};
  country argentina = {"ARG", 44.2};
  
  imprime(brasil);
  imprime(argentina);
  
  muda(&brasil, &argentina);
  
  imprime(brasil);
  imprime(argentina);
  return 0;
}
