#include <stdio.h>
#include<stdbool.h>

bool isPrimo(int k) {
  int i;
  int sum=0;
  for (i=1;i<=k;i++) {
    if(k%i==0) {
      sum++;
    }
  }
  return (sum==2) ? true : false;
}

int main () {
 int k;
 scanf ("%d", &k);
 if (isPrimo (k)) {
 printf ("PRIMO\n");
 }
 else {
 printf ("COMPOSTO\n");
 }
 return 0;
}
