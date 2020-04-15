#include <stdio.h>
#include <string.h>

double media(int n, int m[n][n]) {
  int i, j;
  double media, soma=0, k=0;
  for (i=0;i<n;i++) {
      for (j=0;j<i;j++) {
          soma += m[i][j];
          k++;
      }
  }
  media = soma/k;
  return media;
}

double soma(int n, int m[n][n]) {
    int i, j;
    double soma=0;
    for (i=0;i<n;i++) {
        for (j=0;j<i;j++) {
            soma += m[i][j];
        }
    }
    return soma;
}

int main() {
    char comando[61];
    int n, i, j;
    scanf("%s", comando);
    scanf("%d", &n);
    int m[n][n];
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            scanf("%d", &m[i][j]);
        }
    }

    (strcmp(comando, "S")==0) ? printf("%.1lf\n", soma(n, m)) : printf("%.1lf\n", media(n, m));
    return 0;
}
