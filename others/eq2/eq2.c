#include <stdio.h>
#include <math.h>
int main() {
    float a, b, c;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    float delta = ((b*b)-(4*a*c));
    float raiz_1 =  ((-b)+(sqrt(delta)))/(2*a);
    float raiz_2 = ((-b)-(sqrt(delta)))/(2*a);
    printf("%.4f %.4f\n", raiz_1, raiz_2);
}