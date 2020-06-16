#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int key;
    struct node_s *father, *left, *right;
} node;

typedef struct tree_s {
    node *root;
    int size;
} tree;


tree * createTree() {
    tree * t = malloc(sizeof(tree));
    if (t != NULL) {
        t->root = NULL;
        t->size = 0;
    }
    return t;
}

node * createNode(int key) {
    node *n = malloc(sizeof(node));
    if (n != NULL) {
        n->key = key;
        n->father = NULL;
        n->left = NULL;
        n->right = NULL;
    }
}

void insertOnTree(tree *t, int value) {
    node *n = createNode(value);
    int repeated = 0, enter = 0;
    node *son = t->root;
    node *father = NULL;
    while(son != NULL && repeated == 0) {
        if (son->key < n->key) {
            father = son;
            son = son->right;
        }
        else if (son->key > n->key) {
            father = son;
            son = son->left;
        }
        enter++;
    }
    if(enter == 0) {
        t->root = n;
        t->size++;
    }
    else if(enter != 0) {
        if (father->key < n->key) {
            father->right = n;
        }
        else if (father->key > n->key) {
            father->left = n;
        }
        n->father = father;
        t->size++;
    }
}

int searchOnTree(tree *t, int key) {
    node* current = t->root;
    node* aux = NULL;

    while(current!=NULL)
    {
        if(current->key == key)
        {
            return 1;
        }
        else if(current->key < key)
        {
            aux = current;
            current = current->right;
        }
        else if(current->key > key)
        {
            aux = current;
            current = current->left;
        }
    }
    return 0;
}

int main() {
    int n, value;
    scanf("%d", &n);
    tree *t = createTree();
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        if (searchOnTree(t, value) == 0) {
            insertOnTree(t, value);
        }
        else {
            printf("Chave %d ja existe na arvore!\n", value);
        }
    }
}