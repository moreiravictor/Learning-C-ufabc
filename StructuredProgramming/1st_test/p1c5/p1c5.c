#include <stdio.h>
#include <stdlib.h>

void valida(int *n, int *m) {
    if ( *m < *n) {
        int aux = *n;
        *n = *m;
        *m = aux;
    }

}

int *constroi(int n, int m) {
    int sub = m - n +1;
    int num = n;
    //printf("%d", sub);
    int *v = malloc(sub*sizeof(int));

    for (int i=0;i<sub;i++, num++) {
         v[i] = num;
    }
    return v;
}

int main() {
    int n, m;
    scanf ("%d %d", &n, &m);
    valida(&n, &m);

    int *v = constroi(n, m);
    int tam = m-n+1;
    for (int i=0;i<tam;i++) {
        printf("%d\n", v[i]);
    }

    return 0;
}