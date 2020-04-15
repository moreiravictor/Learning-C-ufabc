#include<stdio.h>

void imprimeMin()
{
    int n=0, i=0;
    int menor=0;
    scanf("%d",&n);
    while (n>=0) {
    if (i==0 || n<menor) {
        menor=n;
        }
    scanf("%d",&n);
    i++;
    }

    if (i>0) printf("%d\n",menor); else printf("nenhum numero informado\n");
}


int main () {
 imprimeMin ();
 return 0;
}