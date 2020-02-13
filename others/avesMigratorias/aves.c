#include <stdio.h>
#include <stdlib.h>

void maisComum(int *v, int n) {
    int maisComum = 0, k= 0;
    int *qtd = malloc (6*sizeof(int));
    for (int i = 0;i<n;i++) {
        qtd[v[i]]++;
    }
    for (k = 1;k<6;k++) {
        if (qtd[k] > qtd[maisComum]) maisComum = k;

    }
    printf("%d\n", maisComum);
}
int main () {
    int n;
    scanf("%d", &n);
    int *v = malloc(n*sizeof(int));
    for (int i=0;i<n;i++) {
        scanf("%d", &v[i]);
    }
    maisComum(v, n);
 return 0;
}