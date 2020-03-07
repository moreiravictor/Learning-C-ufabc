#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
  int valor;
  struct node_s *prox;
} node;

typedef struct lista_s {
  node *primeiro;
  node *ultimo;
} lista;

void adiciona (int v, lista *lt){
  node *novo = malloc(sizeof(node));
  novo->valor = v;
  novo->prox = NULL;
  if (lt->primeiro == NULL) {
    lt->primeiro = novo;
    lt->ultimo = novo;
  }
  else {
    lt->ultimo->prox = novo;
    lt->ultimo = novo;
  }
}

int valida (lista lt){
  int sum;
  node *anterior = lt.primeiro;
  for (node *nd = anterior->prox; nd!= NULL ; anterior = anterior->prox ,nd = nd->prox) {
    if (nd->valor > anterior->valor) sum++;
    else return 0;
  }
  return 1;
}

int main(void) {
  lista lt = {NULL, NULL};
  int n = 1;
  while (n!=0) {
    scanf("%d", &n);
    if (n) adiciona(n, &lt);
  }
  if (valida(lt)) {
    printf("SIM\n");
  } else {
    printf("NAO\n");
  }
  return 0;
}
