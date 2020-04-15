#include <stdio.h>
#include <stdbool.h>

bool isBissexto (int ano) {
    if (ano%400==0) {
        return true;
    }
    else if (ano%4==0 && ano%100!=0) {
        return true;
    }
    else return false;
}




int main () {
 int ano;
 scanf ("%d", &ano);
 if (isBissexto (ano))
 printf ("ANO BISSEXTO\n");
 else
 printf ("ANO NAO BISSEXTO\n");
 return 0;
}