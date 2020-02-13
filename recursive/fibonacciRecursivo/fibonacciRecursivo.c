#include <stdio.h>

long fibonacciRecursivo(int n) {
    if (n==1) return 0;
    else if (n<=3) return 1;
    long a = fibonacciRecursivo(n-1);
    long b = fibonacciRecursivo(n-2);
    return a+b;
}


int main () {
 int n;
 scanf ("%d", &n);
 n-2;
 printf ("%ld\n", fibonacciRecursivo (n));
 return 0;
}