#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element_s {
    char *word;
    int qt;
    struct element_s *next;
    struct element_s *before;
} element;

typedef struct list_s {
    element *first;
    element *last;
    int size;
} list;

element *createElement(char *word) {
    element *element = malloc(sizeof(element));
    element->word = malloc(100);
    strcpy(element->word, word);
    element->qt = 1;
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

element * verifyWord(list *l, char *word) {
    element *current = l->first;
    while(current != NULL && strcmp(current->word, word) != 0) {
        current = current->next;
    }
    return current;
}

void insertOnList(list *l, char *word) {
    element *element_exist = verifyWord(l, word);
    //case where the word hasn't been "notgoogled" yet
    if (element_exist == NULL) {
        element *new = createElement(word);
        if (l->first == NULL) {
            l->first = new;
            l->last = new;
        }
        else {
            l->last->next = new;
            new->before = l->last;
            l->last = new;
        }
    }
    //case where word has been "notgoogled"
    else {
        element_exist->qt++;
        element *current = l->first;
        while(current != element_exist && current->qt > element_exist->qt) {
            current = current->next;
        }
        if(current != element_exist) {
            if(current != l->first && element_exist == l->last) {
                element_exist->before->next = element_exist->next;
                l->last =  element_exist->before;
                element_exist->before = current->before;
                element_exist->next = current;
                element_exist->before->next = element_exist;
                element_exist->next->before = element_exist;
            }
            else if(current != l->first) {
                element_exist->before->next = element_exist->next;
                element_exist->next->before = element_exist->before;
                element_exist->next = current;
                element_exist->before = current->before;
                element_exist->before->next = element_exist;
                element_exist->next->before = element_exist;
            }
            else if(current == l->first && element_exist == l->last) {
                element_exist->before->next = element_exist->next;
                l->first = element_exist;
                element_exist->next = current;
                current->before = element_exist;
                element_exist->before = NULL;

            }
            else if(current == l->first) {
                element_exist->before->next = element_exist->next;
                element_exist->next->before = element_exist->before;
                l->first = element_exist;
                element_exist->next = current;
                current->before = element_exist;
                element_exist->before = NULL;
            }

        }
    }
}

void printBeginLast(list *list) {
    if(list->first != NULL) {
        element *current = list->first;
        while(current != NULL) {
            printf("%s [%d]\n", current->word, current->qt) ;
            current = current->next;
        }
    }
}

int main() {
    list *l = createList();
    char *word = malloc(100);
    while (scanf("%s\n", word) == 1) {
        insertOnList(l, word);
        word = malloc(100);
    }
    printBeginLast(l);
    return 0;
}