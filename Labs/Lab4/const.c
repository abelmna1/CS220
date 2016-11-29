#include <stdio.h>

int main(){
  /*const int *p1;
  const int *p2;
  p1++; (*p1)++;  p2++; (*p2)++;
  
  alteration of values in const int *p1 and const int *p2 
  printf("%p ", p1);  printf("%d\n", *p1);
  
  printf("%p ", p2); printf("%d\n", *p2); */
 
 int const *p1; int const *p2;
 p1++; (*p1)++;  p2++; (*p2)++;
 printf("%p ", p1);  printf("%d\n", *p1);
  
  printf("%p ", p2); printf("%d\n", *p2);
  

  
  return 0;
}
