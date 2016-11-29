#include <stdio.h>
#include <stdlib.h>


int main(){
 int x = 10;
 while(x > 0){
   int *p = (int *) malloc (x * 0x1000);
     *p = 1;
      printf("%d\n", x);
      free(p);
      x ++;

    }
  
   
return 0;
}
