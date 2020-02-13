#include<stdio.h>
#include <stdbool.h>

void createVector(int n, int v[]) {
  int k;
  for (k=0;k<n;k++) {
    scanf("%d", &v[k]);
  }
}

bool buscaSegura(int n, int v[], int m) {
  int i;
  for (i=0;i<n;i++) {
    if (m==v[i]) return true;
  }
  return false;
}

int main () {

  int n, m;
  scanf("%d", &n);
  int v[n];
  createVector(n, v);
  while (scanf("%d", &m)==1) {
    (buscaSegura(n, v, m)) ? printf("SIM\n") : printf("CHAVE NAO ENCONTRADA\n");
  }

  return 0;
}
