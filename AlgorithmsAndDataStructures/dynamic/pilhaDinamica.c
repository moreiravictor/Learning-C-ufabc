#include <stdio.h>
#include <stdlib.h>

typedef struct element_s {
    int key;
    struct element_s *before;
} element;

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

element *createElement(int key) {
    element *element = malloc(sizeof(element));
    if (element != NULL) {
        element->before = NULL;
        element->key = key;
    }
    return element;
}

void stackUp(stack *stack, int key) {
    element *new = createElement(key);
    if (stack->top != NULL) {
        new->before = stack->top;
        stack->top = new;
    }
    else {
        stack->top = new;
    }
    stack->size++;
}

void unstack(stack *stack) {
    if (stack->top != NULL) {
        element *top_before = stack->top;
        stack->top = stack->top->before;
        stack->size--;
        printf("[%d]\n", top_before->key);
        free(top_before);
    }
}

void printStack(stack *stack) {
    element *element = stack->top;
    int i = 0;
    while (i < stack->size) {
        (i == stack->size-1) ? printf("%d\n", element->key) : printf("%d ", element->key);
        i++;
        element = element->before;
    }
}

int main() {
    char option;
    int new_element;
    stack *stack = createStack();
    while(scanf(" %c", &option) == 1) {
        switch(option) {
            case('E'):
                scanf("%d", &new_element);
                stackUp(stack, new_element);
                break;
            case('D'):
                unstack(stack);
                break;
            case('M'):
                printStack(stack);
                break;
        }
    }
    return 0;
}