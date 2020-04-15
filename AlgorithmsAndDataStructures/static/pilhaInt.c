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
        stack->elements[stack->top] = element;
    }
}

void unstack(stack *stack) {
    if (stack->top != -1) {
        stack->top--;
    }
}

void printBottomTop(stack stack) {
    for (int i = 0; i <= stack.top; i++) {
        (i < stack.top) ? printf("%d ", stack.elements[i]) : printf("%d\n", stack.elements[i]);
    }
}

void printTopBottom(stack stack) {
    for (int i = stack.top; i >= 0; i--) {
        (i > 0) ? printf("%d ", stack.elements[i]) : printf("%d\n", stack.elements[i]);
    }
}
void printElementOnTop(stack stack) {
    if (stack.top > -1) printf("%d\n", stack.elements[stack.top]);
}

int main() {
    int size, element;
    char option;

    scanf("%d", &size);
    stack *stack = malloc(sizeof(stack));
    initStack(stack, size);

    while(scanf(" %c", &option) != EOF) {

        switch(option) {
            case('E'):
                scanf("%d", &element);
                stackUp(stack, element);
                break;
            case('D'):
                unstack(stack);
                break;
            case('X'):
                printTopBottom(*stack);
                break;
            case('B'):
                printBottomTop(*stack);
                break;
            case('T'):
                printElementOnTop(*stack);
        }

    }


    return 0;
}
