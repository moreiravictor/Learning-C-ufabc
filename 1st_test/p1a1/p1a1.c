#include <stdio.h>
#include <stdlib.h>
double calcula(int n, double v[n+1], int i) {


    if (i<n) {
        return v[i] + 1/(calcula(n, v, ++i));
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    double v[n+1];
    for (int i = 0;i<=n;i++) {
        scanf("%lf", &v[i]);
    }
    printf("%.2lf\n", (calcula(n, v, 0)));
  return 0;
}