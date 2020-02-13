#include<stdio.h>

int main()
{
    int n=0;
    int i=0;
    int soma=0;
    scanf("%d",&n);
    for(i=1;i<n;i++) {
        if (n%i==0) soma+=i;
    }

    if (soma==n) printf("SIM\n");
    else printf("NAO\n");
    return 0;
}