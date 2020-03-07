#include <stdio.h>
#include <stdlib.h>

int calcula(int *v, int i) {
    if (i == 0) return 0;
    else if (i == 1) {
        if (v[i-1] > 0) return v[i-1];
        else return 0;
    }
    else {
        return ( calcula(v, i-1) > calcula(v, i-2) ) ? (v[i-1] + calcula(v, i-1)) : (v[i-1] + calcula(v, i-2));
    }
}

int main() {
    int n, *v;
    scanf("%d", &n);
    v = malloc(n*sizeof(int));

    for (int i = 0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    for (int  i = 0; i<=n; i++) {
        printf("F(%d) = %d\n", i, calcula(v, i));
    }


    return 0;
}