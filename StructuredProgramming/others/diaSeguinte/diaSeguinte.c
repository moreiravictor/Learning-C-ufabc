#include <stdio.h>


int main() {
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);
    if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 ||mes==10)
    {
      if (dia<31)
      {
        dia++;
      }
      else
      {
      dia=1;
      mes=mes+1;
      }
    }
    else if (mes==4||mes==6||mes==9||mes==11)
    {
      if (dia < 30)
      {
        dia++;
      }
      else
      {
        dia=1;
        mes=mes+1;
      }
    }
    else if (mes==12)
    {
      if (dia<31)
      {
        dia++;
      }
      else
      {
        dia=1;
        mes=1;
        ano++;
      }
    }
    else if (mes==2)
    {
      if (dia<28)
      {
        dia++;
      }
      else if (ano%400==0 || (ano%4==0 & ano%100!=0))
      {
        if (dia==28) dia++;
        else
        {
          dia=1;
          mes++;
        }
      }
      else
      {
        dia=1;
        mes++;
      }
    }
    printf("%d %d %d\n",dia,mes,ano);
    return 0;
}