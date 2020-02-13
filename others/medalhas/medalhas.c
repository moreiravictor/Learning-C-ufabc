#include <stdio.h>

void imprimeMedalhas(int um, int dois, int tres) {

if(um<dois && um<tres) {
 if(dois<tres) {
  printf("1\n2\n3\n");
 }
 else {
  printf("1\n3\n2\n");
 }
}
else if(dois<um && dois<tres) {
 if(um<tres) {
  printf("2\n1\n3\n");
 }
 else {
 printf("2\n3\n1\n");
 }
}
 else {
  if(um<dois) {
   printf("3\n1\n2\n");
  }
  else {
   printf("3\n2\n1\n");
  }
 }
}

int main () {
 int x, y, z;
 scanf ("%d", &x);
 scanf ("%d", &y);
 scanf ("%d", &z);
 imprimeMedalhas (x, y, z);
 return 0;
}