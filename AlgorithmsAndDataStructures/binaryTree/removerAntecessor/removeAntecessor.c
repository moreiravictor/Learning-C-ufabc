#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node* left;
    struct node* right;
    struct node* father;
} node;

typedef struct tree {
    int N;
    struct node* root;
} tree;


tree* createtree(int N) {
    tree* t = (tree*) malloc(sizeof(tree));

    if(t!=NULL) {
        t->N = N;
        t->root = NULL;
    }

    return t;
}

node* createnode(int key) {
    node* no = (node*) malloc(sizeof(node));

    if(no!=NULL) {
        no->father = NULL;
        no->left = NULL;
        no->right = NULL;
        no->key = key;
    }
    return no;
}

void include(tree *t, int value) {
    node *n = createnode(value);
    int repeated = 0;
    if (t->root == NULL) {
        t->root = n;
        t->N++;
    }
    else {
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
            else {
                repeated = 1;
            }
        }
        if(repeated == 0) {
            if (father->key < n->key) {
                father->right = n;
            }
            else if (father ->key > n->key) {
                father->left = n;
            }
            n->father = father;
            t->N++;
        }

    }
}

void  preOrdem(node *root) {
    if (root != NULL) {
        printf("%d\n", root->key);
        preOrdem(root->left);
        preOrdem(root->right);
    }
}

void printTree(tree *t, node* n) {
    if (t->root != NULL) {
        preOrdem(t->root);
    }
}

node * search(tree* t, int key) {
    node* current = t->root;
    node* aux = NULL;

    while(current!=NULL) {
        if(current->key == key) {
            return current;
        }
        else if(current->key < key) {
            aux = current;
            current = current->right;
        }
        else if(current->key > key) {
            aux = current;
            current = current->left;
        }
    }
    return NULL;
}

node* antecessor (node* rem){
    node *ant=NULL, *atu=rem->left;
    while (atu != NULL){
        ant = atu;
        atu = atu->right;
    }
    if (ant->left != NULL){
        if (ant == rem->left)
            rem->left = ant->left;
        else
            (ant->father)->right = ant->left;
        (ant->left)->father = ant->father;
    }    else {
        if (ant == rem->left)
            rem->left = NULL;
        else
            ant->father->right = NULL;
    }
    return ant;
}

int filholeft(node* filho){
    if (filho->father==NULL)
        return 0;
    else {
        if (filho->father->left==filho)
            return 1;
        else
            return 0;
    }
}

void removerAnt(tree* a1, int x){
    node *father = NULL, *filho = a1->root;
    while (filho!=NULL && filho->key!=x){
        father=filho;
        if (x > filho->key)
            filho=filho->right;
        else
            filho=filho->left;
    }
    if (filho!=NULL){
        if (filho->left==NULL && filho->right==NULL){
            if (father==NULL)
                a1->root = NULL;
            else {
                if (filholeft(filho))
                    father->left=NULL;
                else
                    father->right=NULL;
            }
        }
        else if (filho->left==NULL || filho->right==NULL){
            node* neto = filho->left;
            if (neto==NULL)
                neto = filho->right;
            //Nó é root?
            if (father == NULL)
                a1->root = neto;
            else {
                if (filholeft(filho))
                    father->left=neto;
                else
                    father->right=neto;
            }
            neto->father=father;
        }
        else {
            node* antec = antecessor(filho);
            antec->father = filho->father;
            antec->left = filho->left;
            antec->right = filho->right;
            if (filho->left != NULL)
                (filho->left)->father = antec;
            if (filho->right != NULL)
                (filho->right)->father = antec;
            if (father==NULL)
                a1->root=antec;
            else {
                if (filholeft(filho))
                    father->left = antec;
                else
                    father->right = antec;
            }
        }
        free (filho);
    }
}

int main() {
    int i,j,k,l;
    int N,key, M;

    scanf("%d", &N);

    tree* t = createtree(N);

    for(i=0;i<N;i++) {
        scanf("%d", &key);

        if(search(t,key) == NULL)  {
            include(t,key);
        }
    }

    scanf("%d", &M);
    for(i=0;i<M;i++) {
        scanf("%d", &key);
        removerAnt(t, key);
    }

    printTree(t, t->root);
    free(t);

    return 0;
}