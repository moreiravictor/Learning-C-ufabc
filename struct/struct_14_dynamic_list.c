#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
  int v;
  struct node_s *prox;
} node;

typedef struct lista_s {
  node *primeiro;
} lista;

void init_lista(lista *lt) {
  lt->primeiro = NULL;
}

void adiciona (int v, lista *lt){
  node *novo = malloc(sizeof(node));
  novo->v = v;
  novo->prox = lt->primeiro;
  lt->primeiro = novo;
}

node *ultimo (lista *lt) {
  node *nd = NULL;
    for (nd = lt->primeiro; nd!=NULL; nd = nd->prox) {
      if (nd->prox == NULL) return nd;
  }
  return nd;
}

int main(void) {
  lista lt;
  init_lista(&lt);
  int n=0;
  while(n>=0) {
    scanf("%d", &n);
    if(n>=0)
      adiciona(n, &lt);
  }
  node *u = ultimo(&lt);
  if (u) {
    printf("%d\n", u->v);
  } else {
    printf("Lista vazia\n");
  }
 return 0;
}
