#include <stdio.h>

int main() {
    int n=6, i=0, j=0, amp=0, ampMaior = 0;
    int m[n][n];
    //lendo m
    for (i = 0; i<n;i++) {
        for (j = 0; j<n;j++) {
            scanf("%d", &m[i][j]);
        }
    }
    for (i = 1; i<n-1;i++) {
        for (j = 1; j<n-1;j++) {
            amp = m[i-1][j-1]+m[i-1][j]+m[i-1][j+1]+m[i][j]+m[i+1][j-1]+m[i+1][j]+m[i+1][j+1];
            if (i == 1 && j == 1) ampMaior = amp;
            if (amp>ampMaior) ampMaior = amp;
        }
    }
    printf("%d\n", ampMaior);

    return 0;
}