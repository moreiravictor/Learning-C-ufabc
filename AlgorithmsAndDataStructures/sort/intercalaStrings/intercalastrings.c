#include <stdio.h>
#include <stdlib.h>

int main() {
    int size_first, size_second, size_result;
    int i, j, k;

    scanf("%d", &size_first);
    char *first = (char *) calloc(size_first, sizeof(char));
        scanf("%s", first);


    scanf("%d", &size_second);
    char *second = (char *) calloc(size_second, sizeof(char));
        scanf("%s", second);
 
    size_result = size_first + size_second;
    char *result = calloc(size_result, sizeof(char));


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

    for(i=0;i < size_result;i++) {
        if(i + 1 == size_result) printf("%c\n", result[i]);
        else printf("%c", result[i]);
    }

    free(first);
    free(second);
    free(result);
    return 0;
}