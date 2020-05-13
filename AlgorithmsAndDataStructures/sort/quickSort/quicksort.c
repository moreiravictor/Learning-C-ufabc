#include <stdio.h>
#include <stdlib.h>

void print(int *a, int size) {
    for (int i = 0; i < size; i++) {
        (i < size-1) ? printf("%d ",  a[i]) : printf("%d\n",  a[i]);
    }
}

int partition(int *a, int left, int right, int size) {
    int value =  a[right];
    int aux;
    int i;  
    int pm = left - 1;

    for (i = left; i <= right;  i++) {
      if (a[i] <= value) {
          pm++;
          aux = a[i];
          a[i] = a[pm];
          a[pm] = aux;
      }

      print(a, size);
    }

    return pm;

}

void quicksort(int *a, int left, int right, int size) {
    int pivot;
    if (left < right) {
        pivot = partition(a, left, right, size);
        quicksort(a, left, pivot-1, size);
        quicksort(a, pivot+1, right, size);
    }
}


int main() {
    int size;
    scanf("%d", &size);

    int *a = (int*) calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d",  &a[i]);
    }

    int left = 0;
    int right = size-1;

    print(a, size);

    quicksort(a, left, right, size);

    print(a, size);

    free(a);

    return 0;
}