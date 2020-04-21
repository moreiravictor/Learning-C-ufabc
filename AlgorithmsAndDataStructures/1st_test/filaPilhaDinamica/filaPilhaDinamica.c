#include <stdio.h>
#include <stdlib.h>
typedef struct element_s {
    int key;
    struct element_s *next;
} element;

typedef struct queue_s {
    element *begin;
    element *end;
    int size;
} queue;

typedef struct stack_s {
    element *top;
    int size;
} stack;

stack *createStack() {
    stack *stack = malloc(sizeof(stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

element * createElement(int value) {
    element *new = malloc(sizeof(element));
    new->key = value;
    new->next = NULL;
    return new;
}

queue * createQueue() {
    queue *q = malloc(sizeof(queue));
    q->begin = NULL;
    q->end = NULL;
    q->size = 0;
    return q;
}

void insertOnQueue(queue *q, int key) {
    element *new_element = createElement(key);

    if(q->begin == NULL) {
        q->begin = new_element;
        q->end = new_element;
    }
    else {
        element *current = q->begin;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = new_element;
        q->end = new_element;
    }
    q->size++;
}

void dequeue(queue *q) {
    if (q->begin != NULL) {
        element *old_begin = q->begin;
        q->begin = q->begin->next;
        q->size--;
        free(old_begin);
    }
}

void eaclesToStack(queue *q, stack *s) {
    s->size = q->size;
    s->top = q->begin;
}

void printStack(stack *stack) {
    element *element = stack->top;
    int i = 0;
    while (i < stack->size) {
        printf("%d\n", element->key);
        i++;
        element = element->next;
    }
}

int main() {
    char option;
    int insertion;
    queue *q = createQueue();
    stack *s = createStack();
    while (scanf(" %c", &option ) == 1) {
        switch(option) {
            case('E'):
                scanf("%d", &insertion);
                insertOnQueue(q, insertion);
                break;
            case('D'):
                dequeue(q);
                break;
            case('P'):
                eaclesToStack(q, s);
                break;
            case('M'):
                printStack(s);
                break;
        }
    }
    return 0;
}