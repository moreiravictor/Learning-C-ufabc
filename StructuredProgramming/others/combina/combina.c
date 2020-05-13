#include<stdio.h>
#include<stdlib.h>

int* combina(int*v, int*w, int n, int m);

int main() 
{
    int n, m, i;
    int *v, *w, *r;
    
    scanf("%d %d", &n, &m);
    
    v = malloc(sizeof(int) * n);
    
    w = malloc(sizeof(int) * m);
    
    for(i = 0; i < n; i++) 
    {
        scanf("%d", &v[i]);
    }
    
    for(i = 0; i < m ; i++) 
    {
        scanf("%d", &w[i]);
    }
    
    r = combina(v, w, n, m);
    
    for(i = 0; i < n+m-1; i++) 
    {
        printf("%d ", r[i]);
    }
    printf("%d\n", r[n+m-1]);
    
    free(v);
    free(w);
    free(r);
}

int* combina(int*v, int*w, int n, int m) {
    int i,j;
    int* r;    
    r = malloc((n+m)*sizeof(int));
    
    for(i=0;i<n;i++) {
        r[i] = v[i];
    }
    
    for(j=n,i=m-1;j<(m+n) && i>=0;j++,i--) {
        r[j] = w[i];
    }
    return r;
}
