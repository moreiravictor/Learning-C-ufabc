#include <stdio.h>

void calculaTroco(int preco, int valorPago) {
    int troco = valorPago-preco, pago = 0, valores[7] = {100, 50, 20, 10, 5, 2}, qtdNotas = 0;
    for (int i=0;i<6;i++) {
        for (int k=0;k<6;k++) {
            if (valores[i]+valores[k] == troco) {
                printf("possible\n");
                pago++;
                k=6; i=6;
            }
        }
    }
    if(pago==0) {
        printf("impossible\n");
    }

}

int main() {
    int preco, valorPago;
    scanf("%d %d", &preco, &valorPago);
    while (preco!=0 && valorPago!=0) {

    calculaTroco(preco, valorPago);


    scanf("%d %d", &preco, &valorPago);
    }

    return 0;
}