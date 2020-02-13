#include <stdio.h>

int main() {
    int a,b;
    scanf("%d", &a);
    scanf("%d", &b);
    int div = a/b;
    int res = a%b;
    printf("%d %d\n",div, res);

    return 0;
}