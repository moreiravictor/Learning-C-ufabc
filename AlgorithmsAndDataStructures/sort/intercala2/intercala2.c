#include <stdio.h>
#include <stdlib.h>

int main() {
    int size_first;
    int size_second;
    int size_result;

    scanf("%d", &size_first);
    scanf("%d", &size_second);
    size_result = size_first + size_second;

    int *vu = calloc(size_result, sizeof(int));
    int *vaux = calloc(size_result, sizeof(int));

    for (int i = 0; i < size_result; i++) {
        scanf("%d", &vu[i]);
    }

    int i = 0, k= 0;
    int j = size_first;
    while(i < size_first && j < size_result) {
        if (vu[i] <= vu[j]) {
            vaux[k] = vu[i];
            i++;
            k++;
        }
        else {
            vaux[k] = vu[j];
            j++;
            k++;
        }   
    }

    //cases where one of the vectors has ended
    for (; i < size_first; i++, k++) {
        vaux[k] = vu[i];
    }
    
    for (; j < size_result; j++, k++) {
        vaux[k] = vu[j];
    }

    for (int l = 0; l < size_result; l++) {
        printf("%d\n",  vaux[l]);
    }

    free(vaux);
    free(vu);

    return 0;
}