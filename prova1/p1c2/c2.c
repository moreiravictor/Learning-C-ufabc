#include <stdio.h>
#include <stdlib.h>
int main() {
    double n, qtdPos = 0, qtdNeg = 0;
    double somaPos = 0, somaNeg = 0;
    double num;
    scanf("%lf", &n);
    for (int i = 0; i<n; i++) {
        scanf("%lf", &num);
        if (num>0) {
            qtdPos++;
            somaPos += num;
        }
        else {
            qtdNeg++;
            somaNeg += num;
        }

    }
    double mediaPos = somaPos/qtdPos;
    double mediaNeg = somaNeg/qtdNeg;
    printf("%.6lf ", mediaNeg);
    printf("%.6lf\n", mediaPos);



    return 0;
}