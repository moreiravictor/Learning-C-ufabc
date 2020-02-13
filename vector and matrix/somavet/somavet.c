#include<stdio.h>

long soma(long v[], long n) {
    long i, sum = 0;
    for (i=0;i<n; i++) {
        sum += v[i];
    }
    return sum;
}

int main() {
    long n, i;
    scanf("%ld", &n);
    long v[n];

    for (i = 0; i<n; i++) {
        scanf("%ld", &v[i]);
    }
    printf("%ld\n",soma(v, n));

    return 0;
}