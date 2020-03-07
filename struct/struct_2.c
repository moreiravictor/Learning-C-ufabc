#include <stdio.h>

typedef struct cor_s {
  int r;
  int g;
  int b;
} cor;

int main(void) {
  cor c1 = {127, 25, 138};
  cor c2 = c1;
  c1.r = 0;
  
  //printf("MUDA\n");
  printf("NAO MUDA\n");
  return 0;
}
