/* #include <stdio.h>
int main(){
    char b[] = "i`bna";
    int k = 1;
    int index;
    for(index =  0; b[index] !=0; index++){
        b[index] = b[index] - k;
        
    } 
    printf("decrypted message is: %s\n", b);
} */
#include <stdio.h>
int main()
{
 char b[] = "SJSFMPCRM WG O USBWIG. PIH WT MCI XIRUS O TWGV PM WHG OPWZWHM HC QZWAP O HFSS, WH KWZZ ZWJS WHG KVCZS ZWTS PSZWSJWBU HVOH WH WG GHIDWR. - OZPSFH SWBGHSWB";
 int k = -38;
 
 int index;
 
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