#include <stdio.h>
#include <stdlib.h>

int ordem_crescente(const void *a, const void *b) {
  int *a_int = (int *) a;
  int *b_int = (int *) b;
  int result = *a_int - *b_int;
  return result;
}

int ordem_decrescente(const void *a, const void *b) {
  int *a_int = (int *) a;
  int *b_int = (int *) b;
  int result = *b_int - *a_int;
  return result;
}

int comp_paridade(const void *a, const void *b) {
  int *a_int = (int *) a;
  int *b_int = (int *) b;
  
  if (*a_int %2 == 0 && *b_int %2 == 0 ) {
    int result = *a_int - *b_int;
    return result;
  }
  else if (*a_int %2 != 0 && *b_int %2 != 0 ) {
    int result = *b_int - *a_int;
    return result;
  }
  else if (*a_int %2 == 0 && *b_int %2 != 0 ) {
    int result = 0;
    return result;
  }
  else {
    int result = 1;
    return result;
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  int *v = malloc(n * sizeof(int));
  for (int i = 0; i <n; i++) {
    scanf("%d", &v[i]);
  }
  qsort(v, n, sizeof(int), comp_paridade);
  
  for (int i = 0; i <n; i++) {
    printf("%d ", v[i]);
  }
  return 0;
}
