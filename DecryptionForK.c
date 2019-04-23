
#include <stdio.h>
int main() 
{
 char b[] = "wWxXyY";
 int k = 100; 
 if(k>26)
 {
     k = k % 26;
 }
 int index = 0;
  for(index = 0; b[index] != 0; index++)
 {
 if(b[index] >= 97 && b[index] <= 122)
 {
 b[index] = b[index] - 32;
 }
 }
 
 for(index = 0; b[index] !=0; index++)
 {
     if(( b[index] < 65) || (b[index] > 90 && b[index] < 97) || (b[index] > 122)) 
     {
       //do nothing to any punctuation  
     }
     else
     {
         b[index] = ((b[index] - 65) - k + 26) % 26 + 65;
     }
         
 }
 printf("encrypted message is %s\n", b);
}