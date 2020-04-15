#include <stdio.h>
#include <stdlib.h>

typedef struct queue_S {
    int *items;
    int begin, end, size;
} queue;

void initList(queue *queue, int size) {
    queue->items = malloc(size*sizeof(int));
    queue->begin = -1;
    queue->end = -1;
    queue->size = size;
}

void insertOnQueue(queue *queue, int item) {
    if (queue->end < (queue->size)-1) {
        queue->end++;
        queue->items[queue->end] = item;

        if (queue->begin == -1) {
            queue->begin++;
        }
    }
}

void removeFromQueue(queue *queue) {
    if (queue->begin > -1) {
        printf("%d\n", queue->items[queue->begin]);
        if (queue->begin < queue->size) {
            queue->begin++;
            if (queue->begin == queue->end+1) {
                queue->begin = -1;
                queue->end = -1;
            }
        }
    }

}

int main() {
    queue *queue = malloc(sizeof(queue));
    int size, item;
    char option;
    scanf("%d", &size);
    initList(queue, size);

    while(scanf(" %c", &option) != EOF) {

        switch (option) {
        case('E'):
                scanf("%d", &item);
                insertOnQueue(queue, item);
            break;
        case('D'):
                removeFromQueue(queue);
            break;
        }
    
    }
    free(queue);
    return 0;
}