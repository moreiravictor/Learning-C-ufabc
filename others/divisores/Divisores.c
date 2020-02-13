#include <stdio.h>

int contaDivisoresPares(int n) {
    int i;
    int numDiv=0;
    for (i=1;i<=n;i++) {
        if (n%i==0) {
            if (i%2==0) {
                numDiv++;
            }
        }
    }
    return numDiv;
}

int main () {
 int n;
 scanf ("%d", &n);
 printf ("%d\n", contaDivisoresPares (n));
 return 0;
}