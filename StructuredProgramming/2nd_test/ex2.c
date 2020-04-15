#include <stdio.h>
#include <stdlib.h>

typedef struct ponto_s {
  int x;
  int y;
} ponto;

typedef struct triangulo_s {
  ponto ponto1;
  ponto ponto2;
  ponto ponto3;
} triangulo;

int valida(ponto ponto1, ponto ponto2, ponto ponto3) {
  int a = ((ponto1.x - ponto2.x)*(ponto2.y - ponto3.y)) - ((ponto2.x - ponto3.x)*(ponto1.y - ponto2.y));
  if (a != 0) return a;
  
  return 0;
}

triangulo *constroi(ponto *ponto1, ponto *ponto2, ponto *ponto3) {
  triangulo *tri = malloc(sizeof(triangulo));
  tri->ponto1 = *ponto1;
  tri->ponto2 = *ponto2;
  tri->ponto3 = *ponto3;
  return tri;
}

void modifica(triangulo *tri) {
  tri->ponto1.x = 2 * tri->ponto1.x;
  tri->ponto1.y = 2 * tri->ponto1.y;
  
  tri->ponto2.x = 2 * tri->ponto2.x;
  tri->ponto2.y = 2 * tri->ponto2.y;
  
  tri->ponto3.x = 2 * tri->ponto3.x;
  tri->ponto3.y = 2 * tri->ponto3.y;
}

int main(void) {
  
  ponto *ponto1 = malloc(sizeof(ponto));
  ponto *ponto2 = malloc(sizeof(ponto));
  ponto *ponto3 = malloc(sizeof(ponto));
  scanf("%d %d", &ponto1->x, &ponto1->y);
  scanf("%d %d", &ponto2->x, &ponto2->y);
  scanf("%d %d", &ponto3->x, &ponto3->y);
  if (valida(*ponto1, *ponto2, *ponto3) != 0 ) {
    triangulo *tri = malloc(sizeof(triangulo));
    tri = constroi (ponto1, ponto2, ponto3);
    modifica(tri);
    printf("%d %d\n", tri->ponto1.x, tri->ponto1.y);
    printf("%d %d\n", tri->ponto2.x, tri->ponto2.y);
    printf("%d %d\n", tri->ponto3.x, tri->ponto3.y);
  }
  else printf("INVALIDO\n");
  
  return 0;
}
