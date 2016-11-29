#include <stdio.h>
#include <time.h>

void forLoop(unsigned int n) {
	unsigned int i;
	for(i = 0; i < n; i++)
		;
}

void whileLoop(unsigned int n) {
	while(n > 0)
		n--;
}

void doWhileLoop(unsigned int n) {
	do { n--; } while (n > 0);
}

int main()
{
    clock_t tic = clock();

    
    /* Call loop function here */
    
    
    /*printf("x = %d\n", x);
    x = 20;
    whileLoop(x);
    printf("x = %d\n", x);
    doWhileLoop(x);
    x= 20;
    printf("x = %d\n", x);
 */
    unsigned int x = 1000000000;
    /*forLoop(x); 
    whileLoop(x); */
     doWhileLoop(x); 
        
    clock_t toc = clock();
    
    
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    printf("Iterations per second: %f\n", (x / ((double)(toc -tic) / CLOCKS_PER_SEC)));

    return 0;
}
