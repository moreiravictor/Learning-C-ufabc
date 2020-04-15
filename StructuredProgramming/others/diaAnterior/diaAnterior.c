#include <stdio.h>


int main() {
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);
    if (mes == 1) {
        if (dia>1) {
            dia--;
        }
        else {
            dia = 31;
            mes = 12;
            ano--;
        }
    }
    else if (mes==12 || mes==5 || mes==7 ||mes==10)
    {
      if (dia>1)
      {
        dia--;
      }
      else
      {
      dia=30;
      mes--;
      }
    }
    else if (mes == 2 || mes==4||mes==6|| mes == 8 ||mes==9||mes==11)
    {
      if (dia> 1)
      {
        dia--;
      }
      else
      {
        dia=31;
        mes--;
      }
    }
    else if (mes==3)
    {
      if (dia>1)
      {
        dia--;
      }
      else if (ano%400==0 || (ano%4==0 & ano%100!=0))
      {
        dia = 29;
        mes--;
      }
      else
      {
        dia=28;
        mes--;
      }
    }
    printf("%d %d %d\n",dia,mes,ano);
    return 0;
}