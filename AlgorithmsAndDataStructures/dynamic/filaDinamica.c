#include <stdio.h>
#include <stdlib.h>

typedef struct element_s {
    int key;
    struct element_s *next;
} element;

typedef struct queue_s {
    element *begin;
    element *end;
} queue;

element *createElement(int key) {
    element *element = malloc(sizeof(element));
    element->key = key;
    element->next = NULL;
    return element;
}

queue *createQueue() {
    queue *q = malloc (sizeof(queue));
    q->begin = NULL;
    q->end = NULL;
    return q;
}

void insertOnQueue(queue *q, int key) {
    element *new = createElement(key);
    //empty queue
    if (q->begin == NULL) {
        q->begin = new;
        q->end = new;
    }
    //queue with items
    else {
        element *current = q->begin;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
        q->end = new;
    }
}

void removeFromQueue(queue *q) {
    if (q->begin != NULL) {
        element *last_begin = q->begin;
        q->begin = last_begin->next;
        printf("<%d>\n", last_begin->key);
        free(last_begin);
    }
}

void printQueue(queue *q) {
    if (q->begin != NULL && q->end != NULL) {
        element *current = q->begin;
        while (current != NULL) {
            // printf("inicio da fila: %d\n", q->begin->key);
            // printf("fim da fila: %d\n", q->end->key);
            (current->next != NULL) ? printf("%d ", current->key) : printf("%d\n", current->key) ;
            current = current->next;
        }
    }
}

int main() {
    char option;
    int insertion;
    queue *q = createQueue();
    while (scanf(" %c", &option ) == 1) {
        switch(option) {
            case('E'):
                scanf("%d", &insertion);
                insertOnQueue(q, insertion);
                break;
            case('D'):
                removeFromQueue(q);
                break;
            case('M'):
                printQueue(q);
                break;
        }
    }
    return 0;
}