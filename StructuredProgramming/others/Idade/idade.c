#include <stdio.h>
int main() {
    int anoAtual, nascimento, idade;
    char nome[61];

    scanf(("%d"), &anoAtual);
    scanf("%s", nome);
    scanf("%d", &nascimento);
    idade = anoAtual-nascimento;
    printf("%s, voce completa %d anos de idade neste ano.\n", nome, idade);

    return 0;
}