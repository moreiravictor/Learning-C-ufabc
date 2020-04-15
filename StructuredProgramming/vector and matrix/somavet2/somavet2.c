#include<stdio.h>

void soma2(long v[], long n, long num) {
    long i, j, soma = 0;
    for (i=0;i<n; i++) {
        for (j=i+1;j<n;j++) {
            if (v[i]+v[j]==num) soma++;
        }
    }
    (soma>0) ? printf("SIM\n") : printf("NAO\n");
}

long main() {
    long n, i, num;
    scanf("%ld", &n);
    long v[n];

    for (i = 0; i<n; i++) {
        scanf("%ld", &v[i]);
    }
    scanf("%ld", &num);

    soma2(v, n, num);

    return 0;
}