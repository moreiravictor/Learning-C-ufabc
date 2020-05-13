#include <stdio.h>
#include <stdlib.h>

struct complex {
    int x;
    int y;
};
struct complexG {
    long long x;
    long long y;
};

struct complex Transform(int A, int B) {
    struct complex C;
    C.x = A;
    C.y = B;
    
    return C;
}

void multiply(struct complex M,struct complex W) {
    struct complexG final;
    
    final.x = ((M.x)*(W.x)) - ((M.y)*(W.y));
    final.y = ((M.y)*(W.x)) + ((M.x)*(W.y));
    
    if(final.y>=0) printf("%lld +%lldi\n", final.x, final.y);
    
    else printf("%lld %lldi\n", final.x, final.y);
    
}

void sum(struct complex M,struct complex W) {
    struct complexG final;
    
    final.x = ((M.x)+(W.x));
    final.y = ((M.y)+(W.y));
    
    if(final.y>=0) printf("%lld +%lldi\n", final.x, final.y);
    
    else printf("%lld %lldi\n", final.x, final.y);
    
}

void subtract(struct complex M,struct complex W) {
    struct complexG final;
    
    final.x = ((M.x)-(W.x));
    final.y = ((M.y)-(W.y));
    
    if(final.y>=0) printf("%lld +%lldi\n", final.x, final.y);
    
    else printf("%lld %lldi\n", final.x, final.y);
}

void divide(struct complex M,struct complex W) {
    struct complexG final;
    
    final.x = (((M.x)*(W.x))+((M.y)*(W.y)))/((W.x*W.x)+(W.y*W.y));
    final.y = (((W.x)*(M.y))-((M.x)*(W.y)))/((W.x*W.x)+(W.y*W.y));
    
    if(final.y>=0) printf("%lld +%lldi\n", final.x, final.y);
    
    else printf("%lld %lldi\n", final.x, final.y);
}

int main() {
    int A,B,C,D;
    char option,i;
    
    while(scanf("%d", &A)!=EOF) {
        scanf("%d", &B);
        scanf("%c", &i);
        scanf(" %c", &option);
        scanf("%d", &C);
        scanf("%d", &D);
        scanf("%c", &i);
        
        
        if(option=='*') multiply(Transform(A,B),Transform(C,D));
        
        else if(option=='+') sum(Transform(A,B),Transform(C,D));
        
        else if(option=='-') subtract(Transform(A,B),Transform(C,D));
        
        else if(option=='/') divide(Transform(A,B),Transform(C,D));
        
    }
    
    return 0;
}
