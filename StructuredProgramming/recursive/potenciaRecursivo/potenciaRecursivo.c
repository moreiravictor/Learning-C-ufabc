#include <stdio.h>

long potenciaRecursivo(int a,int n) {
    if (n==1) {
        return a;
    }
    else if (n==0) {
        return 1;
    }
    else {
        return potenciaRecursivo(a, n-1)*a;
    }
}

int main () {
 int a, n;
 scanf ("%d", &a);
 scanf ("%d", &n);
 printf ("%ld\n", potenciaRecursivo (a, n));
 return 0;
}