#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
char * str = "Quick brown fox jumped over the lazy dog";
void bad(int dummy){
  int *loop_ptr = &dummy;
  
 /* char *ptr = (char *) malloc(sizeof(str)); */
 int * ptr; unsigned int offset = 0;

  while(*loop_ptr != 22){
    offset++;
    loop_ptr++;
  }

  ptr = &dummy + offset;
  /*offset is FROM location of struct in main TO &dummy) */
  *ptr = 1000;
   ptr = ptr-2;
   /*ptr = ptr2 - 2;
   printf("%s\n", *ptr); */
   
   *ptr = str;
   /*ptr2 = str;
   ptr = ptr2 + offset;
   ptr -= (2*sizeof(int));
  ptr = string;
  printf("%s\n", */ 
  
  
  /*ptr2 = &+ 
  printf("%p\n", ptr2); */
 /*printf("Address of dummy = %p\n", &dummy); 
 char sentence[44] = "The quick brown fox jumps over the lazy dog.";
 char * char_ptr = (char *)malloc(sizeof(sentence));
 char_ptr = sentence;*/
 
}

int main(){

  struct {
    char *name;
    int age;
  } student = { .name = "John", .age = 22 };
  bad(sizeof(student));
  printf("student.name = %s\nstudent.age = %d\n" , student.name, student.age);
  return 0;
 }
