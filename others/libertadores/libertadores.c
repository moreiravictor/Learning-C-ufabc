#include <stdio.h>
#include <stdlib.h>

void calculaGanhador(int golsAMandante, int golsBVisitante, int golsBMandante, int golsAVisitante ) {
    int pontosA = 0, pontosB = 0;
    if (golsAMandante>golsBVisitante) pontosA += 3;
    else if (golsBVisitante > golsAMandante) pontosB += 3;
    else {
        pontosA += 1;
        pontosB += 1;
    }
    if (golsBMandante>golsAVisitante) pontosB += 3;
    else if (golsAVisitante > golsBMandante) pontosA += 3;
    else {
        pontosB += 1;
        pontosA += 1;
    }
    if (pontosA>pontosB) printf("Time 1\n");
    else if (pontosB>pontosA) printf("Time 2\n");
    else {
        if ((golsAMandante+golsAVisitante) > (golsBMandante+golsBVisitante) ) printf("Time 1\n");
        else if ((golsAMandante+golsAVisitante) < (golsBMandante+golsBVisitante) ) printf("Time 2\n");
        else if (golsAVisitante > golsBVisitante) printf("Time 1\n");
        else if (golsAVisitante < golsBVisitante) printf("Time 2\n");
        else printf("Penaltis\n");
    }


}

int main() {
  int qtd = 0, golsAMandante, golsBVisitante, golsBMandante, golsAVisitante;
  scanf("%d", &qtd);
  for (int i = 0;i<qtd;i++) {
    scanf("%d x %d", &golsAMandante, &golsBVisitante);
    scanf("%d x %d", &golsBMandante, &golsAVisitante);
    calculaGanhador(golsAMandante, golsBVisitante, golsBMandante, golsAVisitante);
  }

  return 0;
}