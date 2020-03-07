#include <stdio.h>
#include <stdlib.h>

void troca (int v, int n, int w, int m) {
  int a = n;
  n = m;
  m = n;
  int b = v;
  v = w;
  w = b;
}

typedef struct entrada_s {
  int *seq;
  int n;
} entrada;

void imprime (entrada e) {
  printf("%d ", e.n);
  for (int i=0; i<e.n; i++) {
    printf("%d ", e.seq[i]);
  }
  printf("\n");
}
int main(void) {
  int n, m;
  int *v, *w;
  scanf("%d %d", &n, &m);
  v = malloc(n * sizeof(int) );
  w = malloc(m * sizeof(int));
  for(int i=0; i<n; i++) {
    v[i] = i*2 + 1;
  }
  for(int i=0; i<m;  i++) {
    w[i] = i*2;
  }
  entrada *e1 = malloc(sizeof(entrada));
  entrada *e2 = malloc(sizeof(entrada));
  
  e1->seq = v;
  e1->n = n;
  e2->seq = w;
  e2->n = m;
  
  troca(*e1->seq,e1->n, *e2->seq, e2->n);
  
  imprime(*e2);
  imprime(*e1);
  
  return 0;
}
