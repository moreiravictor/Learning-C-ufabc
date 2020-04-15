#include <stdio.h>
#include <stdlib.h>

typedef struct element_s {
    int key;
    struct element_s *next;
    struct element_s *before;
} element;

typedef struct list_s {
    element *first;
    element *last;
    int size;
} list;

element *createElement(int key) {
    element *element = malloc(sizeof(element));
    element->key = key;
    element->next = NULL;
    element->before = NULL;
    return element;
}

list *createList() {
    list *list = malloc(sizeof(list));
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
    return list;
}

void insertOnList(list *list, int key) {
    element *new = createElement(key);
    if(list->first == NULL) {
        list->first = new;
        list->last = new;
        list->size++;
    }
    else {
        element *current = list->first;
        while(key > current->key && current->next != NULL) {
            current = current->next;
        }
        //end of the list
        if (current == list->last && key > current->key) {
            current->next = new;
            new->before = current;
            list->last = new;
        }
        //beginning of the list
        else if (current == list->first && key < current->key) {
            new->next = list->first;
            list->first->before = new;
            list->first = new;
            list->size++;
        }
        //middle of the list
        else if (key < current->key){
            new->next = current;
            new->before = current->before;
            current->before->next = new;
            current->before = new;
            list->size++;
        }
    }
}

void removeFromList(list *list, int key) {
    if (list->first != NULL) {
        element *current = list->first;
        while(key != current->key && current->next != NULL) {
            current = current->next;
        }
        //beginning of the list
        if(current == list->first && current->key == key) {
            list->first = current->next;
            //list contains more than one element
            if (current->next != NULL) {
                current->next->before = NULL;
            }
            //list contains only one element
            else {
                list->last = NULL;
            }
            free(current);
            list->size--;
        }
        //middle of the list
        else if(current->next != NULL && current->key == key) {
            current->before->next = current->next;
            current->next->before = current->before;
            free(current);
            list->size--;
        }
        //end of the list
        else if (current->next == NULL && current->key == key){
            current->before->next = NULL;
            list->last = current->before;
            free(current);
            list->size--;
        }
    }
}

void printBeginLast(list *list) {
    if(list->first != NULL) {
        element *current = list->first;
        while(current != NULL) {
            (current != list->last) ? printf("%d ", current->key) : printf("%d\n", current->key) ;
            current = current->next;
        }
    }
}

void printLastBegin(list *list) {
    if(list->first != NULL) {
        element *current = list->last;
        while(current != NULL) {
            (current != list->first) ? printf("%d ", current->key) : printf("%d\n", current->key) ;
            current = current->before;
        }
    }
}

int main() {
    int key;
    char option;
    list *list = createList();
    while (scanf(" %c", &option) == 1) {
        switch (option){
        case('I'):
            scanf("%d", &key);
            insertOnList(list, key);
            break;
        case('E'):
            scanf("%d", &key);
            removeFromList(list, key);
            break;
        case('M'):
            printBeginLast(list);
            break;
        case('R'):
            printLastBegin(list);
            break;
        }
    }
    free(list);
    return 0;
}