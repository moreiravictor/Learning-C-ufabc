#include <stdio.h>

void calcula(int buracoDesejado, int maiorVelocidade) {
    int i;
    int velocidadesPossiveis = maiorVelocidade;
    while(velocidadesPossiveis>0) {
        maiorVelocidade = velocidadesPossiveis;
        int buraco = 0;
        while (maiorVelocidade>0) {
            for (i = 0; i < maiorVelocidade; i++){
                buraco += maiorVelocidade;
                if (buraco == buracoDesejado ) {
                    printf("possivel\n");
                    maiorVelocidade = 0;
                    velocidadesPossiveis = 0;
                }
            }
            maiorVelocidade--;
        }
        velocidadesPossiveis--;
    }
    if (velocidadesPossiveis != -1) printf("impossivel\n");
}

int main() {
    int n, v;
    scanf("%d %d", &n, &v);
    while (n != 0 && v != 0) {
        calcula(n, v);
        scanf("%d %d", &n, &v);
    }
}