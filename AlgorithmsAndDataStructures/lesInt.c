#include  <stdio.h>
#include <stdlib.h>
typedef struct list_s {
    int *elements;
    int qt_elements;
    int size;
} list;

int searchOnList(list *list, int chosen_element) {
    for (int i = 0; i < list->qt_elements; i++) {
        if (list->elements[i] == chosen_element) {
            return i;
        }
    }
    return -1;
}

void startList(list *list, int size) {
    list->elements = (int*) malloc(size * sizeof(int));
    list->qt_elements = 0;
    list->size = size;
}

void moveListRight(list *list, int index) {
    for (int j = 1, k = 0; j<= list->qt_elements-index; j++, k++) {
        list->elements[list->qt_elements-k] = list->elements[list->qt_elements-j];
    }
}

void moveListLeft(list *list, int index) {
    for(int i = index; i < list->qt_elements-1; i++) {
        list->elements[i] = list->elements[i+1];
    }
    list->qt_elements--;
}

void insertOnList(list *list, int chosen_element) {
    if (searchOnList(list, chosen_element) == -1) {
        if (list->qt_elements == 0) {
            list->elements[0] = chosen_element;
            list->qt_elements  ++;
        }
        else if (list->qt_elements < list->size) {
            int was_minor = 0;
            for(int i = 0; i < list->qt_elements; i++) {
                if (chosen_element < list->elements[i]) {
                    was_minor++;
                    moveListRight(list,i);
                    list->elements[i] = chosen_element;
                    list->qt_elements++;
                    i = list->qt_elements;
                }
            }
            if (was_minor == 0) {
                list->elements[list->qt_elements] = chosen_element;
                list->qt_elements++;
            }
        }
    }
}


void removeFromList(list *list, int chosen_element) {
    int index = searchOnList(list, chosen_element);
    if (index != -1) {
        moveListLeft(list, index);
    }
}

void printList(list list) {
    for (int i = 0; i < list.qt_elements; i++) {
        (i < list.qt_elements -1) ? printf("%d ", list.elements[i]) : printf("%d\n", list.elements[i]);
    }
}

int main(void) {
    list list;
    int qt_inputs, chosen_element, inputs;
    char insert_erase;
    scanf("%d", &qt_inputs);
    startList(&list, qt_inputs);

    int is_scanned;

    do {
        is_scanned = scanf("%c", &insert_erase);
    } while (insert_erase == '\n');
    
    while (is_scanned == 1) {
        switch(insert_erase) {
            case 'I':
                scanf("%d", &chosen_element);
                insertOnList(&list, chosen_element);
                break;
            case 'R':
                scanf("%d", &chosen_element);
                removeFromList(&list, chosen_element);
                break;
            case 'B':
                scanf("%d", &chosen_element);  
                (searchOnList(&list, chosen_element) == -1) ? printf("NAO\n") : printf("SIM\n") ;
                break;
            case 'M':
                printList(list);
                break;
        }

        do {
            is_scanned = scanf("%c", &insert_erase);
        } while (insert_erase == '\n');

    }
    return 0;
}