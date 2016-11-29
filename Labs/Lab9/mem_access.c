#include <sys/time.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>

#define STEP_SIZE 128
#define READ_SIZE 64 * (1024 * 1024)
#define PAGE_SIZE 4096
#define NG 32
#define PAGES_IN_NG  (NG* 1024 * 1024)/PAGE_SIZE

int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1)
{
    long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
    result->tv_sec = diff / 1000000;
    result->tv_usec = diff % 1000000;

    return (diff<0);
}

void timeval_print(char *str, struct timeval *tv)
{
    printf("%s %ld sec, %06ld micro sec\n", str, tv->tv_sec, tv->tv_usec);
}

void test_hdd(){
 
   struct timeval tvDiff, tvStart, tvEnd;
   int i, fd; 
   
   char  c[STEP_SIZE];
   
   
   fd = open("file64M", O_RDONLY);  /*implies read-only */
   gettimeofday(&tvStart, NULL); 
   for(i = 0; i < READ_SIZE; i+=STEP_SIZE)
      read(fd, &c[0], STEP_SIZE);
   gettimeofday(&tvEnd, NULL);
   timeval_subtract(&tvDiff, &tvEnd, &tvStart);
   timeval_print("HDD ACCESS: ", &tvDiff);
}

void test_mem(){
   struct timeval tvDiff, tvStart, tvEnd;  
   int i,j;
   int * ptr;
   unsigned char *mem_arr[PAGES_IN_NG];
   
   /*allocate N GB on the heap */
   ptr = (int *) malloc(sizeof(int) * NG); 
   
   for(i = 0; i < PAGES_IN_NG; i++){
     if((mem_arr[i] = memalign(PAGE_SIZE, PAGE_SIZE)) == NULL){
       printf("Malloc failed...\n");
    }
   }
   gettimeofday(&tvStart, NULL);
   for(i = 0; i < PAGES_IN_NG; i++)
     for(j = 0; j < PAGE_SIZE; j++)
       mem_arr[i][j]++;
     gettimeofday(&tvEnd, NULL);
     timeval_subtract(&tvDiff, &tvEnd, &tvStart);
     timeval_print("MEM SERIAL ACCESS: ", &tvDiff);


   gettimeofday(&tvStart, NULL);
   for(j = 0; j < PAGE_SIZE; j++)
     for(i = 0; i < PAGES_IN_NG; i++)
        mem_arr[i][j]++;
     gettimeofday(&tvEnd, NULL);
     timeval_subtract(&tvDiff, &tvEnd, &tvStart);
     timeval_print("MEM PAGE STEP ACCESS: ", &tvDiff);


}

int main(){
  test_hdd();   
  test_mem();

return 0;
}
