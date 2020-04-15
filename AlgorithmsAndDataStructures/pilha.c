#include <stdio.h>
#include <stdlib.h>

typedef struct stack_s {
    int *elements;
    int size;
    int top;
} stack;

void initStack(stack *stack, int size) {
    stack->elements = (int*) malloc(size*sizeof(int));
    stack->size = size;
    stack->top = -1;
}

void stackUp(stack *stack, int element) {
    if (stack->top < stack->size-1) {
    stack->top++;
        if (stack->top < stack->size) {
            stack->elements[stack->top] = element;
        }
    }
}

void unstack(stack *stack) {
    stack->top--;
}

void printBottomTop(stack stack) {
    for (int i = 0; i <= stack.top; i++) {
        printf("%d\n", stack.elements[i]);
    }
}

void printTopBottom(stack stack) {
    for (int i = stack.top; i >= 0; i--) {
        printf("%d\n", stack.elements[i]);
    }
}

int main() {
    int size, element, is_scanned;
    char option;

    scanf("%d", &size);
    stack *stack = malloc(sizeof(stack));
    initStack(stack, size);

    do {
        is_scanned = scanf("%c", &option);
    }   while (option == '\n');

    while(is_scanned == 1) {

        switch(option) {
            case('E'):
                scanf("%d", &element);
                stackUp(stack, element);
                break;
            case('D'):
                unstack(stack);
                break;
            case('T'):
                printTopBottom(*stack);
                break;
            case('B'):
                printBottomTop(*stack);
                break;
        }

        do {
        is_scanned = scanf("%c", &option);
    }   while (option == '\n');

    }


    return 0;
}