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

void imprime(lista lt) {
  for(node *atual=lt.primeiro; atual!=NULL; atual=atual->prox) {
    printf("%d ", atual->v);  
  }
  printf("\n");
}

void concatena (lista *lt1, lista *lt2) {
  node *nd;
  for (nd = lt1->primeiro;nd->prox != NULL; nd = nd->prox) {
  }
  nd->prox = lt2->primeiro;
}

int main(void) {
  lista lt1, lt2;
  init_lista(&lt1);
  init_lista(&lt2);
  int n=1;
  while(n>0) {
    scanf("%d", &n);
    if(n>0)
      adiciona(n, &lt1);
  }
  n = 1;
  while(n>0) {
    scanf("%d", &n);
    if(n>0)
      adiciona(n, &lt2);
  }
  concatena(&lt1, &lt2);
  imprime(lt1);
  lt2.primeiro->v = 0;
  imprime(lt1);
 return 0;
}
