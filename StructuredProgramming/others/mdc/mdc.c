#include <stdio.h>

int mdc(int a, int b) {
    int i=0, menor=0, divisor = 0;
    if(a<b) menor=a; else menor=b;
    for (i=1;i<=menor;i++) {
        if (a%i==0 && b%i==0) {
            divisor = i;
        }
    }
    return divisor;
}



int main () {
 int a, b;
 scanf ("%d", &a);
 scanf ("%d", &b);
 printf ("%d\n", mdc (a, b));
 return 0;
}