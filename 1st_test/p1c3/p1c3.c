#include <stdio.h>
#include <stdlib.h>


int main() {
    int n, linha;
    scanf ("%d", &n);
    int m[n][n], h[n][n];
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            scanf("%d", &m[i][j]);
        }
    }
        for(int i = 0;i<n;i++) {
            scanf("%d", &linha);
            for(int j = 0;j<n;j++) {
                h[i][j] = m[linha-1][j];
            }
        }
    for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if (j == n-1) printf("%d\n", h[i][j]);
                else printf("%d ", h[i][j]);
            }
        }

    return 0;
}