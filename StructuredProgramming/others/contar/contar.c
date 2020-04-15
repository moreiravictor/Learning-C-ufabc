#include<stdio.h>

int contar(int v[], int n, int num) {
    int i, sum = 0;
    for (i = 0; i <n; i++) {
        if (v[i]>=num) sum++;
    }
    return sum;
}

int main() {
    int n, i, num;
    scanf("%d", &n);
    int v[n];
    for (i = 0; i <n; i++) {
        scanf("%d", &v[i]);
    }
    scanf("%d", &num);
    printf("%d\n", contar(v, n, num));
    return 0;
}