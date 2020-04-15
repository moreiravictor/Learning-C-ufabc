#include <stdio.h>
#include <stdlib.h>

typedef struct element_s {
    int key;
    struct element_s *next;
} element;

typedef struct list_s {
    element *begin;
    int size;
} list;


list * startList() {
    struct list_s *list = (struct list_s*) malloc(sizeof(struct list_s));
    if (list != NULL) {
        list->begin = NULL;
        list->size = 0;
    }
    return list;
}

element * createElement(int key) {
    struct element_s *element = (struct element_s*) malloc(sizeof(struct element_s));
    if (element != NULL) {
        element->key = key;
        element->next = NULL;
    }
    return element;
}

void insertOnList(list *list, int key) {
    element *new_element = createElement(key);
    //empty list case
    if (list->size == 0) {
        list->begin = new_element;
        list->size++;
    }
    //not empty case
    else {
        element *current = list->begin, *before = NULL;
        while( current != NULL && key > current->key) {
            before = current;
            current = current->next;
        }
        //end of the list
        if (current == NULL) {
            before->next = new_element;
            list->size++;
        }
        //beginning of the list
        else if (before == NULL && new_element->key != current->key) {
            new_element->next = list->begin;
            list->begin = new_element;
            list->size++;
        }
        //middle of the list
        else if (key != current->key) {
            before->next = new_element;
            new_element->next = current;
            list->size++;
        }
    }
}

void removeFromList(list *list, int key) {
    element *current = list->begin, *before = NULL;
    if (list->size > 0) { 
        while(current != NULL && current->key <= key) {
            if (current == list->begin && key == current->key) {
                list->begin = current->next;
                list->size = list->size - 1;
                free(current);
                return;
            }
            else if (key == current->key) {
                before->next = current->next;
                list->size = list->size - 1;
                free(current);
                return;
            }
            before = current;
            current = current->next;
        }
    }
}

void searchOnList(list *list, int key) {
    element *current = list->begin;
    while(current != NULL && current->key <= key) {
        if (current->key == key) {
            printf("SIM\n");
            return;
        }
        current = current->next;
    }
    printf("NAO\n");
}

void printList(list *l) {
    element *it = l->begin;
    int i;
    for (i = 0; i < l->size-1; i++) {
        printf ("%d ", it->key);
        it = it->next;
    }
    if (l->size > 0) {
        printf ("%d\n", it->key);
    }
}

int main() {
    struct list_s *list = startList();
    char option;
    int new_element;

    while(scanf(" %c", &option) == 1) {
        switch(option) {
            case ('I'):
                scanf("%d", &new_element);
                insertOnList(list, new_element);
                break;
            case('L'):
                printList(list);
                break;
            case('R'):
                scanf("%d", &new_element);
                removeFromList(list, new_element);
                break;
            case('B'):
                scanf("%d", &new_element);
                searchOnList(list, new_element);
                break;
        }
    }
    return 0;
}