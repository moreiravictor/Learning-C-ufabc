#include <stdio.h>

int contar (int vetor[1000], int n, int x) {
    int soma=0;
    if (n>0) {
        if (vetor[n-1]>=x) {
            soma++;
        }
        n--;
        soma += contar(vetor, n, x);
    }
    return soma;
}



int main () {
    int n, i, vetor[1000], x;
    scanf ("%d", &n);
    for (i = 0; i < n; i++) {
        scanf ("%d", &vetor[i]);
    }
    scanf ("%d", &x);
    printf ("%d\n", contar (vetor, n, x));
    return 0;
}