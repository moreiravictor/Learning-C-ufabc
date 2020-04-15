#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
  int v;
  struct node_s *prox;
} node;

typedef struct lista_s {
  node *primeiro;
  node *ultimo;
} lista;

void imprime_node(node nd) {
  printf("%d\n",nd.v);
}

void init_lista(lista *lt) {
  lt->primeiro = NULL;
  lt->ultimo = NULL;
}

void adiciona (int v, lista *lt){
  node *nd = malloc(sizeof(node));
  if (lt->primeiro == NULL) {
    nd->v = v;
    lt->primeiro = nd;
    lt->ultimo = nd;
  }
  else {
    nd->v = v;
    lt->ultimo->prox = nd;
    lt->ultimo = nd;
  }
}

void percorre(lista lt) {
  for(node *nd=lt.primeiro; nd!=NULL;nd = nd->prox)
    imprime_node(*nd);
}

int main(void) {
  lista lt;
  init_lista(&lt);
  adiciona(12, &lt);
  adiciona(23, &lt);
  adiciona(34, &lt);
  adiciona(45, &lt);
  percorre(lt);
  
  return 0;
}
