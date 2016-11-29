/* Implementation of the fact function goes here. */

int fact(int n) {
 int result, count;
 result = 1; 
 count = n;
 if(n <= 1) return result;
 else{

   while(count > 1 ) {
   result = result * count;
   count--;
   } 
   return result; 
 }
 
}


 
 
