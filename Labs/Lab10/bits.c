#include <sys/time.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>

#define BIT(n) (1<< (n))
#define BIT_SET(v, mask) (v |= (mask))
#define BIT_CLEAR(v, mask) (v &= ~(mask))
#define BIT_FLIP(v, mask) (v ^= (mask))
#define IS_SET_ANY(v, mask) (v & (mask))
#define IS_CLEAR_ANY(v, mask) (v & ~(mask))   
#define BIT_MASK(len) (BIT(len)-1)
#define BF_MASK(start,len) ( BIT_MASK(len)<<(start) )
#define BF_PREP(x, start, len) ( ((x)&BIT_MASK(len)) << (start) )
#define BF_GET(y, start, len) ( (y >> (start)) & (BIT_MASK(len) ) )          
#define BF_SET(y, x, start, len) ((BIT_CLEAR((y), BF_MASK((start), (len)))) | (BF_PREP(x, (start), (len))) )


unsigned int get_page_offset(unsigned int address);
unsigned int get_tlb_id(unsigned int address);
unsigned int get_tlb_tag(unsigned int address);
unsigned int set_page_offset(unsigned int address, unsigned int new_offset);
unsigned int set_tlb_id(unsigned int address, unsigned int new_tlb_id);
unsigned int set_tlb_tag(unsigned int address, unsigned int new_tag);

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

void print_in_binary(unsigned int x){
 int i;

 for(i = 31; i >= 0; i--){
  
  if(IS_SET_ANY(x, BIT(i))) printf("1");
  else printf("0"); 
 }
 printf("\n");
}

unsigned int get_page_offset(unsigned int address){
 return  BF_GET(address, 0, 12);

}

unsigned int get_tlb_id(unsigned int address){
  unsigned int id, i;

  
  return BF_GET(address, 12, 3);  
}

unsigned int get_tlb_tag(unsigned int address){

 return BF_GET(address, 24, 8);
}

unsigned int set_page_offset(unsigned int address, unsigned int new_offset){
 return  BF_SET(address, new_offset, 0, 12);
}

unsigned int set_tlb_id(unsigned int address, unsigned int new_tlb_id){
  return BF_SET(address, new_tlb_id, 12, 3);
}



unsigned int set_tlb_tag(unsigned int address, unsigned int new_tag){
 return BF_SET(address, new_tag, 24, 8);
}

/*
int main(){
 unsigned int i;
 unsigned int x = 5;
  unsigned int addr1 = (unsigned int)0xf712c0d0;
 unsigned int newAddr1, newAddr2, newAddr3;
 newAddr1 = newAddr2 = newAddr3 = 0; 
 printf("%x\n", addr1); 
 
 unsigned int offset1, tlbID1, tlbTag1, offset2, tlbID2, tlbTag2;
 offset1 = tlbID1 = tlbTag1 = 0;
 offset2 = 0x1a3; tlbID2 = 0; tlbTag2 = 0x84;
 offset1 = get_page_offset(addr1);

 printf("offset: 0x%x\n", offset1); 
 tlbID1 = get_tlb_id(addr1);
 printf("id: 0x%x\n", tlbID1);

 tlbTag1 = get_tlb_tag(addr1);
 printf("tag: 0x%x\n", tlbTag1); 
 printf("offset: \n");
 print_in_binary(offset1);
 printf("ID: \n");
 print_in_binary(tlbID1);
 printf("tag: \n");
 print_in_binary(tlbTag1);
 printf("**********************************\n");  
 newAddr1 = set_page_offset(addr1, offset2);
 printf("new offset: 0x%x\n", newAddr1);
 printf("original address: \n");
 print_in_binary(addr1);
 printf("new offset: \n");
 print_in_binary(newAddr1);
 newAddr2 = set_tlb_id(addr1, tlbID2);
 newAddr3 = set_tlb_tag(addr1, tlbTag2);
 printf("new ID: 0x%x\n", newAddr2); 
 printf("new ID: \n");
 print_in_binary(newAddr2);
 printf("new tag: 0x%x\n", newAddr3);
 printf("new Tag: \n");
 print_in_binary(newAddr3);

  return 0; 
} */


