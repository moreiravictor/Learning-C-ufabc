#include <stdio.h>
#include <stdbool.h>
bool isEspelho (int a, int b) {
    if ((a/1000==b%10) && (((a/100)%10)==((b%100)/10)) && (b/1000==a%10) && (((b/100)%10)==((a%100)/10))) return true;
    else return false;
}

int main () {
 int a, b;
 scanf ("%d", &a);
 scanf ("%d", &b);
 if (isEspelho (a, b))
 printf ("espelho\n");
 else
 printf ("nao espelho\n");
 return 0;
}