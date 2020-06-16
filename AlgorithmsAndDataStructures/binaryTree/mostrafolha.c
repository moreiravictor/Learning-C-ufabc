#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int elemento;
    struct No* fEsq;
    struct No* fDir;
    struct No* pai;
}no;

typedef struct Arvore
{
    int N;
    struct No* raiz;
}arvore;

arvore* criaArvore(int N);
void inclusao(arvore* Arv, int elemento);
int busca(arvore* Arv,int elemento);
no* criaNo(int elemento);
void printTree(arvore *a, no* n);

int main()
{
    int i,j,k,l;
    int N,elemento;

    scanf("%d", &N);

    arvore* Arv = criaArvore(N);

    for(i=0;i<N;i++)
    {
        scanf("%d", &elemento);

        if(busca(Arv,elemento) == 0)
        {
            inclusao(Arv,elemento);
        }
    }

    printTree(Arv, Arv->raiz);

    return 0;
}

void printTree(arvore *a, no* n) {
    if (n->fDir == NULL && n->fEsq == NULL) {
        printf("%d\n", n->elemento);
    }
    if (n->fEsq != NULL) {
        printTree(a, n->fEsq);
    }
    if (n->fDir != NULL) {
        printTree(a, n->fDir);
    }
}

arvore* criaArvore(int N)
{
    arvore* Arv = (arvore*) malloc(sizeof(arvore));

    if(Arv!=NULL)
    {
        Arv->N = N;
        Arv->raiz = NULL;
    }

    return Arv;
}

no* criaNo(int elemento)
{
    no* No = (no*) malloc(sizeof(no));

    if(No!=NULL)
    {
        No->pai = NULL;
        No->fEsq = NULL;
        No->fDir = NULL;
        No->elemento = elemento;
    }
    return No;
}

int busca(arvore* Arv, int elemento)
{
    no* atual = Arv->raiz;
    no* aux = NULL;

    while(atual!=NULL)
    {
        if(atual->elemento == elemento)
        {
            return 1;
        }
        else if(atual->elemento < elemento)
        {
            aux = atual;
            atual = atual->fDir;
        }
        else if(atual->elemento > elemento)
        {
            aux = atual;
            atual = atual->fEsq;
        }
    }
    return 0;
}

void inclusao(arvore* Arv, int elemento)
{
    no* No = criaNo(elemento);

    no* atual = Arv->raiz;
    no* aux = NULL;
    int entrou = 0;

    while(atual!=NULL)
    {
        if(atual->elemento < elemento)
        {
            aux = atual;
            atual = atual->fDir;
        }
        else if(atual->elemento > elemento)
        {
            aux = atual;
            atual = atual->fEsq;
        }
        entrou++;
    }

    if(entrou == 0)
    {
        Arv->raiz = No;
    }

    else if(entrou!= 0)
    {
        if(aux->elemento < elemento)
        {
            aux->fDir = No;
        }
        else if(aux->elemento > elemento)
        {
            aux->fEsq = No;
        }
    }

}