#include <stdio.h>

int mmc(int a, int b) {
    int i=0, maior, mult = 0, j=0, min=0;
    if(a>b) maior=a; else maior=b;
    for (i=0, j=maior;i<=0;j++) {
        if (j%a==0 && j%b==0) {
            i++;
            min = j;
        }
    }
    return min;
}

int main () {
 int a, b;
 scanf ("%d", &a);
 scanf ("%d", &b);
 printf ("%d\n", mmc (a, b));
 return 0;
}