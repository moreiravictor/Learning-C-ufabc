#include <stdio.h>

char *decToHex(int n) {
    int aux;
    aux = n/16;

}

int main() {
    int n;
    // while(scanf("%d", &n) == 1){
    //     printf("%s\n", decToHex(n));
    // }
    scanf("%d", &n);
    printf("%d\n", &(n/16));
    return 0;
}