#include <stdio.h>

typedef struct cor_s {
  int r;
  int g;
  int b;
} cor;

int main() {
  cor c;
  scanf("%d", &c.r);
  scanf("%d", &c.g);
  scanf("%d", &c.b);
  
  printf("r=%d g=%d b=%d", c.r, c.g, c.b);
  return 0;
}
