#include <stdio.h>
#include <stdlib.h>


int main(){

  int i;
  for(i = 0; i < 100000000000000000; i+= 1000000){
     int *p = (int *) malloc (i * 0x1000);
     printf("%d\n", i);
   }
   return 0;
}
