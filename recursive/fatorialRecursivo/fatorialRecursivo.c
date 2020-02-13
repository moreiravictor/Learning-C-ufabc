#include <stdio.h>

long fatorialRecursivo(int n) {
    if (n==1 || n==0) return 1;
    else {
        return fatorialRecursivo(n-1)*n;
    }
}


int main () {
 int n;
 scanf ("%d", &n);
 printf ("%ld\n", fatorialRecursivo (n));
 return 0;
}