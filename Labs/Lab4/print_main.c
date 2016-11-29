#include <stdio.h>

int main(){

unsigned char *ptr = (unsigned char *)&main;
*ptr = 9;
do{
 printf("%x\n", *ptr);
 ptr++;
}  while(*ptr != 0xc3);
   /*afterwards*/
   printf("%x\n", *ptr);
return 0;
}
    



