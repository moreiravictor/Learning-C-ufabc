#include <stdio.h>

typedef struct cor_s {
  int *r;
  int *g;
  int *b;
} cor;

int main(void) {
  cor c;
  int r, g, b;
  scanf("%d %d %d", &r, &g, &b);
  c.r = &r;
  c.g = &g;
  c.b = &b;
  printf("r=%d g=%d b=%d\n", *c.r, *c.g, *c.b);
  return 0;
}
