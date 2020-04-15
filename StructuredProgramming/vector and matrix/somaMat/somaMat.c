#include <stdio.h>

int main() {
    int n;
    int i=0, j=0;
    scanf("%d", &n);
    int m[n][n];
    int h[n][n];
    int soma[n][n];

    for (i = 0; i<n;i++) {
        for (j = 0; j<n;j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (i = 0; i<n;i++) {
        for (j = 0; j<n;j++) {
            scanf("%d", &h[i][j]);
        }
    }

    for (int i = 0; i<n;i++) {
        for (int j = 0; j<n;j++) {
            soma[i][j] = m[i][j]+h[i][j];
            if (j < n-1)printf("%d ", soma[i][j]);
            else printf("%d\n", soma[i][j]) ;
        }
    }

    return 0;
}