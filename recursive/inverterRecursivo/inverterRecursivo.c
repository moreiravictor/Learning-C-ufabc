#include <stdio.h>

void imprime(int v[1000], int i, int n) {
    if (i<n-1) {
        printf("%d ", v[n-i-1]);
        i++;
        imprime(v, i, n);
    }
    else {
        printf("%d\n", v[n-i-1]);
    }
}


int main () {
    int n, i, vetor[1000];
    scanf ("%d", &n);
    for (i = 0; i < n; i++) {
    scanf ("%d", &vetor[i]);
    }
    imprime (vetor, 0, n);
    return 0;
}