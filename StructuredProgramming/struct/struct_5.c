
#include <stdio.h>
#include <math.h>
typedef struct prova_s {
  double notas[100];
  int n;
  double media;
  double minimo;
  double maximo;
  double variancia;
} prova;

double media(double v[100], prova *p) {
  double soma = 0; int i;
  for(i = 0;i<p->n;i++) {
      soma += v[i];
  }
  return p->media = soma/i;
  
}

double minimo(double v[100], prova p) {
  for(int i = 0;i<p.n;i++) {
      if (i == 0) p.minimo = v[i];
      else if (v[i]<p.minimo) p.minimo = v[i];
  }
  return p.minimo;
}

double maximo(double v[100], prova p) {
  for(int i = 0;i<p.n;i++) {
      if (i == 0) p.maximo = v[i];
      else if (v[i]>p.maximo) p.maximo = v[i];
  }
  return p.maximo;
}

double variancia (double v[100], prova p) {
  double parteDeCima = 0, parteDeBaixo = (p.n)-1;
  for (int i = 0;i<p.n; i++) {
    parteDeCima += pow((p.media)-v[i], 2);
  }
  p.variancia = parteDeCima/parteDeBaixo;
  return p.variancia;
}

int main() {
  prova p;
  
  scanf("%d", &p.n);
  for(int i = 0;i < p.n; i++) {
    scanf("%lf", &p.notas[i]);
  }
  
  printf("%.2lf ", media(p.notas, &p));
  printf("%.2lf ", minimo(p.notas, p));
  printf("%.2lf ", maximo(p.notas, p));
  printf("%.2lf", variancia(p.notas, p));
  return 0;
}
