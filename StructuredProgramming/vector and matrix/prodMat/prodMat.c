#include <stdio.h>

int main() {
    int n;
    int i=0, j=0, k = 0;
    scanf("%d", &n);
    int m[n][n], h[n][n], prod[n][n];

    for (i = 0; i<n;i++) {
        for (j = 0; j<n;j++) {
            prod[i][j] = 0;
        }
    }

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

    for (i=0;i<n;i++){
      for (j=0;j<n;j++){
        for (k=0;k<n;k++){
          prod[i][j] += m[i][k]*h[k][j];
        }
      }
    }

    for (i = 0; i<n;i++) {
        for (j = 0; j<n;j++) {
             (j<n-1) ? printf("%d ",prod[i][j] ) : printf("%d\n",prod[i][j] );
        }
    }

    return 0;
}