#include<stdio.h>
#include<stdlib.h>


int *combina(int *v, int *w, int n, int m) {
    int *r = malloc((m+n)*sizeof(int));
    for (int i=0;i<n;i++) {
        r[i] = v[i];
    }
    for (int k=n, l=m-1;k<(m+n);k++, l--) {
        r[k] = w[l];
    }
    return r;

}



int main() {
 int n, m, i;
 int *v, *w, *r;
 scanf("%d %d", &n, &m);
 v = malloc(sizeof(int) * n);
 w = malloc(sizeof(int) * m);
 for(i = 0; i < n; i++) {
 scanf("%d", &v[i]);
 }
 for(i = 0; i < m ; i++) {
 scanf("%d", &w[i]);
 }
 r = combina(v, w, n, m);
 for(i = 0; i < n+m-1; i++) {
 printf("%d ", r[i]);
 }
 printf("%d\n", r[n+m-1]);
 free(v);
 free(w);
}