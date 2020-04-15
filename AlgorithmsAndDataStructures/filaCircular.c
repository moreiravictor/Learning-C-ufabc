#include <stdio.h>
#include <stdlib.h>

typedef struct queue_S {
    int *items;
    int begin, end, size;
} queue;

void initList(queue *queue, int size) {
    queue->items = malloc(size*sizeof(int));
    queue->begin = 0;
    queue->end = 0;
    queue->size = size;
}

void insertOnQueue(queue *queue, int item) {
    int new_end = (queue->end + 1)%(queue->size);
    if (new_end != queue->begin) {
        queue->items[queue->end] = item;
        queue->end = new_end;
    }
}

void removeFromQueue(queue *queue) {
    if (queue->begin != queue->end) {
        printf("%d\n", queue->items[queue->begin]);
        if (queue->begin < queue->size) {
            int new_begin = (queue->begin+1)%queue->size;
            queue->begin = new_begin;
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