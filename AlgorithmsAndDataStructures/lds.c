#include <stdlib.h>
#include <stdio.h>

typedef struct item_s {
    int value;
    struct item_s *next;
} item;

typedef struct list_s {
    int qt_items;
    item *first;
} list;

void initList(list *list) {
    list->first = NULL;
    list->qt_items = 0;
};


int main() {
    int value;
    list *a = malloc(sizeof(list));
    
    return 0;
}