#include <stdio.h>

void arredonda(int *v, int inicio, int fim) {
    if (inicio<fim) {
        if (v[inicio]%10!=0) {
            while (v[inicio]%10!=0){
                v[inicio]++;
            }
        }
        inicio++;
        arredonda(v, inicio, fim);
    }
}

int main() {
    int inicio , fim, i;
    int v[20];
    scanf("%d %d", &inicio, &fim);
    for (i=0; i<20; i++) {
        scanf("%d", &v[i]);
    }
    arredonda(v, inicio, fim);
    for(i=0; i<19; i++) {
        printf("%d ", v[i]);
    }
    printf("%d\n", v[19]);
}