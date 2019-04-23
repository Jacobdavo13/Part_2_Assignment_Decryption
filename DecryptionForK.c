#include <stdio.h>
void DecK(char message[], int key); //Function prototype for DecK (Decryotion for K)
int main() 
{
    char message[] = "SSTTUU"; //inputted message to be decrypted
    int key = 100; //rotational cipher key
    DecK(message, key); //Function which prints decrypted message from key and message provided
}
 
void DecK(char message[], int key) 
{
    printf("Inputted message was: %s\n", message);
    if(key>26) //used if key is too large which will create ASCII charaters that are not letters
    //Example if key = 100 and message[index] = 65 (equation below), 65 - 65 = 0, 0 - 100 + 26 = -74, -74 % 26 = -22, -22 + 65 = 43 which is not an upper case ASCII charater 
    {
        key = key % 26; //key by %26 makes sure the value of key is changed to the remainder of key/26 which is between 0 to 25.
    }
    int index; //declares a pointer to be used later
    for(index = 0; message[index] != 0; index++) //sets up a for loop to run through every character in the array
    {
        if(message[index] >= 97 && message[index] <= 122) //if statement determines if letters are lower case
        {
            message[index] = message[index] - 32; // if letters are lower case -32 changes them to upper case
        }
    }
    for(index = 0; message[index] !=0; index++) //for loop 
    {
        if(( message[index] < 65) || (message[index] > 90 && message[index] < 97) || (message[index] > 122)) //these inequalities are for punctuation and symbols and ensure that they are not changed
        {
            //do nothing to any punctuation  
        }
        else //if the characters are upper case letters this occurs
        {
            message[index] = ((message[index] - 65) - key + 26) % 26 + 65; //turning the ASCII character to a number between 0 and 25 through -65 and then taking away the key to move the letter back to where it was before it was encrypted
//
        }
         
    }
    printf("This message decrypted is: %s\n", message); //prints the decrypted message
}