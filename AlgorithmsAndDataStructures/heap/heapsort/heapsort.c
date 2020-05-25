#include <stdio.h>
#include <stdlib.h>
int left_son(int i) {
    return 2*i + 1;
}
int right_son(int i) {
    return 2*i + 2;
}
int father(int i) {
    return (i-1)/2;
}
int last_father(int n) {
    return (n/2) - 1;
}
void change(int *v, int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void lift(int *v, int n, int i) {
    int e = left_son (i), d = right_son (i), menor = e;
    if (e < n) {
        if (d < n && v[d] >= v[menor]) {
            menor = d;
        }
        if (v[i] < v[menor]) {
            change (v, i, menor);
            lift (v, n, menor);
        }
    }
}

void makeHeap(int *v, int n) {
    int u = last_father (n), i;
    for (i = u; i >= 0; i--) {
        lift (v, n, i);
    }
}

void print(int *v, int size) {
    for(int i = 0; i < size; i++) {
        (i == size-1) ? printf("%d\n", v[i]) : printf("%d ", v[i]);
    }
}

int selectMax(int *v, int size) {
    change(v, 0, size-1);
    return size-1;
}

void heapSort(int *v, int size) {
    int i;
    makeHeap(v, size);
    for (i = size-1; i >= 0; i--) {
        print(v, size);
        size = selectMax(v, size);
        lift(v, size, 0);
    }
}

int main() {
    int size;
    scanf("%d", &size);
    int *v = malloc(size * sizeof (int));
    for(int i = 0; i < size; i++) {
        scanf("%d", &v[i]);
    }
    print(v, size);
    heapSort(v, size);
    print(v, size);

    free (v);
    return 0;
}