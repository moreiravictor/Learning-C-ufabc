#include <stdio.h>
#include <stdlib.h>

void mergeSort(int* v, int esq, int dir, int N);
void intercala(int* v,int esq, int meiomaisum,int dir, int N);

int main()
{
    int N;
    
    scanf("%d", &N);
    
    int *v = (int*) calloc(N,sizeof(int));
    
    int i;
    
    for(i=0;i<N;i++)
    {
        scanf("%d", &v[i]);
    }
    
    int dir = N - 1;
    int esq = 0;
    
    for(i=0;i<N;i++)
    {
        if(i == N - 1) printf("%d\n", v[i]);
        
        else printf("%d ", v[i]);
    }
    
    mergeSort(v,esq,dir,N);
    
    for(i=0;i<N;i++)
    {
        if(i == N - 1) printf("%d\n", v[i]);
        
        else printf("%d ", v[i]);
    }
    
    free(v);
    
    return 0;
}

void mergeSort(int* v, int esq, int dir, int N)
{
    int meio;
    
    if(dir>esq)
    {
        meio = (dir + esq)/2;
        mergeSort(v,esq,meio,N);
        mergeSort(v,meio+1, dir,N);
        intercala(v,esq, meio+1, dir,N);
        
    }
}

void intercala(int* v,int esq, int meiomaisum,int dir,int N)
{
    int i;
    int x = esq;
    int y = meiomaisum;
    int aux;
    int *temp;
    int tamanho = dir - esq + 1;
    
    temp = (int*) calloc(tamanho,sizeof(int));
    
    for(i=0;i<N;i++)
    {
        if(i == N - 1) printf("%d\n", v[i]);
        
        else printf("%d ", v[i]);
    }
    
    i=0;
    
    while(i<tamanho && x<meiomaisum && y<=dir)
    {
        if(v[x] > v[y])
        {
            temp[i] = v[y];
            i++;
            y++;
            
        }
        
        else
        {
            temp[i] = v[x];
            i++;
            x++;
        }
    }
    
    while(i<tamanho && x<meiomaisum)
    {
        temp[i] = v[x];
        x++;
        i++;
    }
    
    while(i<tamanho && y<=dir)
    {
        temp[i] = v[y];
        y++;
        i++;
    }
    
    for(int j=esq,i=0;i<tamanho;j++,i++)
    {
        v[j] = temp[i];
        
        //if(j == tamanho-1) printf("%d\n", temp[i]);
        //else printf("%d ", temp[i]);
    }
    
    
    free(temp);
}


