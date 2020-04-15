#include <stdio.h>
#include <stdlib.h>

typedef struct stack_s {
    char **elements;
    int size;
    int top;
} stack;

void initStack(stack *stack, int size) {
    stack->elements = (char**) malloc(size*sizeof(char*));
    stack->size = size;
    stack->top = -1;
}

void stackUp(stack *stack, char *element) {
    if (stack->top < stack->size-1) {
        stack->top++;
        stack->elements[stack->top] = element;
    }
    else {
        free(element);
    }
}

void unstack(stack *stack) {
    if (stack->top != -1) {
        free(stack->elements[stack->top]);
        stack->top--;
    }
}

void printBottomTop(stack stack) {
    for (int i = 0; i <= stack.top; i++) {
        (i < stack.top) ? printf("%s ", stack.elements[i]) : printf("%s\n", stack.elements[i]);
    }
}

void printTopBottom(stack stack) {
    for (int i = stack.top; i >= 0; i--) {
        (i > 0) ? printf("%s ", stack.elements[i]) : printf("%s\n", stack.elements[i]);
    }
}
void printElementOnTop(stack stack) {
    if (stack.top > -1) printf("%s\n", stack.elements[stack.top]);
}

int main() {
    int size; 
    char option;
    char *element = malloc(1000*sizeof(char));
    stack *stack = malloc (sizeof(stack));
    scanf("%d", &size); 
    initStack(stack, size);

    while(scanf(" %c", &option) == 1) {

        switch(option) {
            case('E'):
                element = malloc(1000*sizeof(char));
                scanf("%s", element);
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
    free(stack);
    return 0;
}
