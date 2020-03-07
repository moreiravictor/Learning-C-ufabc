#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int n;
  scanf("%d", &n);
  int pessoa = n;
  int *porta = malloc((n+200)*sizeof(int));
  int *estado_porta = malloc((n+200)*sizeof(int));
  for (int i = 1;i<=n;i++) {
    estado_porta[i] = 0;
  }
  for (int i = 1;i<=n;i++) {
    porta[i] = i;
  }
  int j = 1;
  while (j<=n) {
    for  (int i = 1;i<=n;i++) {
      if (porta[i]%j == 0) {
        estado_porta[i]++;
      }
    }
  j++;
  }
    
  for (int i = 1;i<=n;i++) {
    if (estado_porta[i]%2 != 0) {
      printf("%d\n", porta[i]);
    }
  }
  
  return 0;
}
