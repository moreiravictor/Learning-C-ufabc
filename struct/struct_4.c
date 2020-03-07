#include <stdio.h>

typedef struct cor_s {
  int *r;
  int *g;
  int *b;
} cor;

int main(void) {
  int r=1, g=2, b=4;
  cor c1 = {&r, &g, &b};
  cor c2 = c1;
  r = 127;
    
  printf("MUDA c1\n");
  printf("MUDA c2\n");
  //printf("NAO MUDA NENHUM\n");
  
  return 0;
}
