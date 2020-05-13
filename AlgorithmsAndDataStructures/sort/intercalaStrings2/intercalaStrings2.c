#include <stdio.h>
#include <stdlib.h>

int main() {
    int size_first;
    int size_second;
    int size_result;

    char *vu = calloc(20000, sizeof(char));
    scanf("%s", vu);

    scanf("%d", &size_first);
    scanf("%d", &size_second);
    size_result = size_first + size_second;
    char *vaux = calloc(size_result, sizeof(char));

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

    for(i=0;i<size_result;i++) {
        if(i + 1 == size_result) printf("%c\n", vaux[i]);
        else printf("%c", vaux[i]);
    }

    free(vaux);
    free(vu);

    return 0;
}