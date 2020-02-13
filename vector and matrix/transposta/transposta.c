#include <stdio.h>

int main() {
    int m,n;
    int i=0, j=0, k = 0, l = 0;
    scanf("%d %d",&m, &n);
    int mat[m][n], trans[n][m];
    //lendo m
    for (i = 0; i<m;i++) {
        for (j = 0; j<n;j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    for (i = 0; i<n;i++) {
        for (j = 0; j<m;j++) {
            trans[i][j] = mat[j][i];
            if (j < m-1)printf("%d ", trans[i][j]);
            else printf("%d\n", trans[i][j]) ;
        }
    }


    return 0;
}