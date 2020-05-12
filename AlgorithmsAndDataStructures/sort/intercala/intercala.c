#include <stdio.h>
#include <stdlib.h>

int main() {
    int size_first;
    int size_second;
    int size_result;

    scanf("%d", &size_first);
    scanf("%d", &size_second);
    size_result = size_first + size_second;

    int *first = calloc(size_first, sizeof(int));
    int *second = calloc(size_second, sizeof(int));
    int *result = calloc(size_result, sizeof(int));
    int i, j, k;
    for (i = 0; i < size_first; i++) {
        scanf("%d", &first[i]);
    }

    for (i = 0; i < size_second; i++) {
        scanf("%d", &second[i]);
    }

    i = 0;
    j = 0;
    k = 0;
    //goes till one of the vectors end
    while(i < size_first && j < size_second) {
        if (first[i] <= second[j]) {
            result[k] = first[i];
            i++;
            k++;
        }
        else {
            result[k] = second[j];
            j++;
            k++;
        }   
    }

    //cases where one of the vectors has ended
    for (; i < size_first; i++, k++) {
        result[k] = first[i];
    }
    

    for (; j < size_second; j++, k++) {
        result[k] = second[j];
    }

    for (int l = 0; l < size_result; l++) {
        printf("%d\n",  result[l]);
    }

    free(first);
    free(second);
    free(result);
    return 0;
}