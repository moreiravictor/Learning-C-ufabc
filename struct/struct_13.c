#include <stdio.h>
#include <stdlib.h>
typedef struct aluno_s {
  int nota;
  int ano;
} aluno;

void print_alunos(int n, aluno *alunos) {
  for (int i = 0; i<n; i++) {
    printf("%d %d\n", alunos[i].nota, alunos[i].ano);
  }
}

int comp_nota(const void *a, const void *b) {
  aluno *a_int = (aluno *) a;
  aluno *b_int = (aluno *) b;
  
  int result = b_int->nota - a_int->nota;
  if (result == 0) result = a_int->ano - b_int->ano;
  return result;
}

int main() {
  int n;
  scanf("%d", &n);
  aluno *alunos = malloc(sizeof(aluno)*n);
  for (int i = 0;i <n; i++) {
    scanf("%d %d", &alunos[i].nota, &alunos[i].ano); 
  }
  
  qsort(alunos, n, sizeof(aluno), comp_nota);
  
  print_alunos(n, alunos);
  
  return 0;
}
