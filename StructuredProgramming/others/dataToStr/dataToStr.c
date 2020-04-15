#include <stdio.h>

int main() {
    int dia, mes, ano;
    while (scanf("%d", &dia)==1) {
        scanf("%d", &mes);
        scanf("%d", &ano);
        if (mes == 1 ) printf ("%02d de Janeiro de %d\n", dia, ano);
        else if (mes == 2 ) printf ("%02d de Fevereiro de %d\n", dia, ano);
        else if (mes == 3 ) printf ("%02d de Marco de %d\n", dia, ano);
        else if (mes == 4 ) printf ("%02d de Abril de %d\n", dia, ano);
        else if (mes == 5 ) printf ("%02d de Maio de %d\n", dia, ano);
        else if (mes == 6 ) printf ("%02d de Junho de %d\n", dia, ano);
        else if (mes == 7 ) printf ("%02d de Julho de %d\n", dia, ano);
        else if (mes == 8 ) printf ("%02d de Agosto de %d\n", dia, ano);
        else if (mes == 9 ) printf ("%02d de Setembro de %d\n", dia, ano);
        else if (mes == 10 ) printf ("%02d de Outubro de %d\n", dia, ano);
        else if (mes == 11 ) printf ("%02d de Novembro de %d\n", dia, ano);
        else if (mes == 12 ) printf ("%02d de Dezembro de %d\n", dia, ano);
    }
    return 0;
}