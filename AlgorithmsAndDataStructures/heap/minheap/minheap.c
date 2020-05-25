#include <stdio.h>
#include <stdlib.h>

void lift(int * v, int node, int left_child, int right_child, int n) {
    if (left_child < n) {
        int bigger = left_child;
        bigger = (right_child < n && v[right_child] <= v[bigger]) ? right_child : left_child ;

        if (v[node] > v[bigger]) {

            int aux = v[node];
            v[node] = v[bigger];
            v[bigger] = aux;

            lift(v, bigger, (2*bigger)+1, (2*bigger)+2, n);
        }
    }
}

void makeHeap(int n, int *v) {
    for (int father = (n/2)-1; father >= 0; father--) {
        lift(v, father, (2*father)+1, (2*father)+2, n);
    }

}

int main() {
    int n;
    scanf("%d", &n);
    while (n != 0) {
        int *v = malloc(n*sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }

        makeHeap(n, v);

        for (int i = 0; i < n; i++) {
            (i == n-1) ? printf("%d\n", v[i]) : printf("%d ", v[i]);
        }

        scanf("%d", &n);
        free(v);
    }
    return 0;
}