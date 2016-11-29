#include <stdio.h>

int main(){
int a = 0xe;
printf("%p ", &a); printf("%x\n", a);
int  *b = &a;
printf("%p ", &b); printf("%p\n", b);
int **c = &b;
printf("%p ", &c); printf("%p\n", c);
int ***d = &c;
printf("%p ", &d); printf("%p\n", d);
return 0;
}
