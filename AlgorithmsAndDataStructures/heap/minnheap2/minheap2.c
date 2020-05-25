#include <stdio.h>
#include <stdlib.h>
int left_son (int i) {
    return 2*i + 1;
}
int right_son (int i) {
    return 2*i + 2;
}
int father (int i) {
    return (i-1)/2;
}
int last_father (int n) {
    return (n/2) - 1;
}
void change (int *v, int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void lift (int *v, int n, int i) {
    int e = left_son (i), d = right_son (i), menor = e;
    if (e < n) {
        if (d < n && v[d] <= v[menor]) {
            menor = d;
        }
        if (v[i] > v[menor]) {
            change (v, i, menor);
            lift (v, n, menor);
        }
    }
}

void makeHeap (int *v, int n) {
    int u = last_father (n), i;
    for (i = u; i >= 0; i--) {
        lift (v, n, i);
    }
}
int searchPosition(int *v, int tam, int n){
    int i = 0;
    for(i = 0; i < tam; i++) if(v[i] == n) break;
    return i;
}
void removeHeap(int *v, int n, int tam){
    int i = searchPosition(v, tam, n);
    int aux;
    if(i < tam){
        aux = v[i];
        v[i] = v[tam-1];
        v[tam-1] = aux;
        makeHeap(v, tam-1);
    }
}
int main(){
    int n, i, op, tam;
    scanf("%d", &tam);
    int *v = malloc(tam * sizeof(int));
    i = 0;
    int j;
    for (j = 0; j < tam; j++) {
       scanf ("%d", &op);
       switch (op) {
        case 1:
                scanf("%d", &n);
                v[i] = n; i++;
                makeHeap(v, i);
                break;
        case 2:
                scanf("%d", &n);
                removeHeap(v, n, i);
                i--;
                break;
            case 3:
                printf("%d\n", v[0]);
                break;
        default:
            break;
       }
    }
    free(v);
    return 0;
}