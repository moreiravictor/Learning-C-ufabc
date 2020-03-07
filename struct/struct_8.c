#include <stdio.h>
#include <stdlib.h>

typedef struct registro_s {
  int identificacao;
  int idade;
  double peso;
} registro;

int main(void) {
  registro *r;
  //seu codigo
  r = malloc(sizeof(registro));
  r->identificacao = 352;
  r->idade = 21;
  r->peso = 72.1;
  printf("%d %d %.1lf", r->identificacao, r->idade, r->peso);
  
  
  
  
  return 0;
}
