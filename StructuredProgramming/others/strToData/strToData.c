#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int dia, ano;
    char mes[200];
    while(scanf ("%d de %s de %d", &dia, mes, &ano) == 3){
      if (strcmp(mes, "Janeiro") == 0 ) printf("%d 1 %d\n", dia, ano);
      else if (strcmp(mes, "Fevereiro") == 0 ) printf("%d 2 %d\n", dia, ano);
      else if (strcmp(mes, "Marco") == 0 ) printf("%d 3 %d\n", dia, ano);
      else if (strcmp(mes, "Abril") == 0 ) printf("%d 4 %d\n", dia, ano);
      else if (strcmp(mes, "Maio") == 0 ) printf("%d 5 %d\n", dia, ano);
      else if (strcmp(mes, "Junho") == 0 ) printf("%d 6 %d\n", dia, ano);
      else if (strcmp(mes, "Julho") == 0 ) printf("%d 7 %d\n", dia, ano);
      else if (strcmp(mes, "Agosto") == 0 ) printf("%d 8 %d\n", dia, ano);
      else if (strcmp(mes, "Setembro") == 0 ) printf("%d 9 %d\n", dia, ano);
      else if (strcmp(mes, "Outubro") == 0 ) printf("%d 10 %d\n", dia, ano);
      else if (strcmp(mes, "Novembro") == 0 ) printf("%d 11 %d\n", dia, ano);
      else if (strcmp(mes, "Dezembro") == 0 ) printf("%d 12 %d\n", dia, ano);
    }
    return 0;
}