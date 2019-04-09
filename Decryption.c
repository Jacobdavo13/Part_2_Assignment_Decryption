#include <stdio.h>
int main(){
    char b[] = "i`bna";
    int k = 1;
    int index;
    for(index =  0; b[index] !=0; index++){
        b[index] = b[index] + k;
        
    } 
    printf("decrypted message is: %s\n", b);
}