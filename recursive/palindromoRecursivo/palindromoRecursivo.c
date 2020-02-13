#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindromo (char str[201], int i, int j) {
    int iguais;
    if(i<(j/2)+1) {
        if (str[i]==str[j]) {
            iguais++;
            isPalindromo(str, i+1, j-1);
        }
        else return false;
    }
    if(iguais == j/2) return true;
}




int main () {
 char str[201];
 while (scanf ("%s", str) == 1) {
 if (isPalindromo (str, 0, strlen(str) - 1)) {
 printf ("sim\n");
 }
 else {
 printf ("nao\n");
 }
 }
 return 0;
}