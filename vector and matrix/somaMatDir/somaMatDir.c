#include <stdio.h>

int main() {
    int n;
    int i=0, j=0, k = 0, l = 0;
    scanf("%d", &n);
    int m[n][n],h[n][n], soma = 0, tam = 2*n;
    int somaDir[tam][tam];
    //lendo m
    for (i = 0; i<n;i++) {
        for (j = 0; j<n;j++) {
            scanf("%d", &m[i][j]);
        }
    }
    //lendo h
    for (i = 0; i<n;i++) {
        for (j = 0; j<n;j++) {
            scanf("%d", &h[i][j]);
        }
    }
    //zerando a matriz somaDireta
    for (i = 0; i<tam;i++) {
        for (j = 0; j<tam;j++) {
            somaDir[i][j] = 0;
        }
    }
    //colocando m na matriz soma
    for (i = 0; i<n;i++) {
        for (j = 0; j<n;j++) {
            somaDir[i][j] = m[i][j];
        }
    }
    //colocando h na matriz soma
    for (i = n, k =0; i<tam;i++, k++) {
        for (j = n, l = 0; j<tam;j++, l++) {
            somaDir[i][j] = h[k][l];
        }
    }
    //printando a matriz soma
    for (i = 0; i<tam;i++) {
        for (j = 0; j<tam;j++) {
            if (j < tam-1)printf("%d ", somaDir[i][j]);
            else printf("%d\n", somaDir[i][j]) ;
        }
    }
    return 0;
}