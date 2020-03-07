#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int inverso(int n) {
    int inverso = 0;
    while (n>0) {
        inverso = n%10 + inverso*10;
        n = n/10;
    }
    return inverso;
}

bool isPalindromo(int n) {
    if (n != inverso(n)) return true;
    else return false;
}

int main() {
    int n;
    scanf("%d", &n);
    while (isPalindromo(n)) {
        n += inverso(n);
    }
    printf("%d\n", n);
}