#include <stdio.h>
#include <stdlib.h>

double medianaDif(int n, double *v) {
    int k, l, qtd = ((n-1)/2);
        for(k=0;k<n;k++) {
            int menores=0, maiores=0;
            for(l=0;l<n;l++) {
                if (k!=l && v[k]>=v[l]) {
                    menores++;
                }
                else if (k!=l && v[k]<=v[l]) maiores++;
            }
            if (maiores == qtd && menores == qtd) {
                return v[k];
                k=n;
            }
        }
}

int main () {
    int c, i;
    scanf("%d", &c);
    for (i=0;i<c;i++) {
        int n, j, m, cont=0;
        scanf("%d", &n);
        double *v = malloc(n*sizeof(double));
        for (j=0;j<n;j++) {
            scanf("%lf", &v[j]);
        }

        for (j=0;j<n;j++) {
            for (m=0;m<n;m++) {
                if(v[j]==v[m] && j!=m) cont++;
            }
        }
        if (cont==((n-1)*n)) {
            printf("%.2lf\n", v[0]);
        }
        else {
            printf("%.2lf", medianaDif(n, v));
        }
    }
    return 0;
}