#include <stdio.h>

int main() {
    int n;
    int i=0, j=0;
    scanf("%d", &n);
    int m[n][n], soma = 0;

    for (i = 0; i<n;i++) {
        for (j = 0; j<n;j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (i = 0; i<n;i++) {
        for (j = 0; j<n-i-1;j++) {
            soma += m[i][j];
        }
    }
    printf("%d\n", soma);

    return 0;
}