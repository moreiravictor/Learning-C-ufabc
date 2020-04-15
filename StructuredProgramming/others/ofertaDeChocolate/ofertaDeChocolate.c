#include<stdio.h>


int quantos(int din, int prec, int m) {
    int embalagens = din/prec;
    int choco=embalagens;
    int aux =0;
    while (embalagens >=m) {

        aux = embalagens/m;
        choco += aux;
        embalagens = embalagens + aux - (m*aux);
    }
    return choco;


}
int main()
{
    int din=0, prec=0, m=0, casos=0;
    scanf("%d",&casos);
    while (casos) {
        scanf("%d %d %d",&din, &prec, &m);
        printf("%d\n",quantos(din, prec, m));
        casos--;
    }
    return 0;
}