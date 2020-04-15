#include <stdio.h>

int catalan(int n) {
    if (n==0) {
        return 1;
    }
    return (((((4*n)-2)))*catalan(n-1)/(n+1));
}

int main() {
    int n;
    scanf("%d", &n);
    while (n!=-1) {
        printf("%d\n", catalan(n));
        scanf("%d", &n);
    }

    return 0;
}