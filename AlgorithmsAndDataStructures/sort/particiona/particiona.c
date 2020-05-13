#include <stdio.h>
#include <stdlib.h>


void partition(int *a, int position, int size) {
    int value =  a[position];
    a[position] = a[size-1];
    a[size-1] = value;
    
    int pm = -1;
    int aux;
    int i;
    for (i = 0; i < size;  i++) {
        if (a[i] <= value) {
            pm++;
            aux = a[i];
            a[i] = a[pm];
            a[pm] = aux;
        }
    }
}

void print(int *a, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n",  a[i]);
    }
}

int main() {
    int size;
    scanf("%d", &size);

    int position;
    scanf("%d", &position);

    int *a = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d",  &a[i]);
    }

    partition(a, position, size);

    print(a, size);

    free(a);

    return 0;
}