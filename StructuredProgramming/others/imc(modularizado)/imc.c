#include <stdio.h>

double calculaIMC (double a, double p) {
    return p/(a*a);
}

void imprimeMensagem(double imc) {
    if (imc<16) printf("Magreza grave\n");
    else if (imc<17) printf("Magreza moderada\n");
    else if (imc<18.5) printf("Magreza leve\n");
    else if (imc<25) printf("Saudavel\n");
    else if (imc<30) printf("Sobrepeso\n");
    else if (imc<35) printf("Obesidade Grau I\n");
    else if (imc<40) printf("Obesidade Grau II (severa)\n");
    else printf("Obesidade Grau III (morbida)\n");
}

int main () {
 double a, p;
 scanf ("%lf", &a);
 scanf ("%lf", &p);
 double imc = calculaIMC (a, p);
 imprimeMensagem (imc);
 return 0;
}