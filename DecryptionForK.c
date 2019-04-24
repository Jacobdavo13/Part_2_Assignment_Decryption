#include <stdio.h>
void DecK(char message[], int key); //Function prototype for DecK (Decryotion for K)
int main() 
{
    char message[] = "SSTTUooooo"; //inputted message to be decrypted
    int key = 22; //rotational cipher key
    DecK(message, key); //Function which prints decrypted message from key and message provided
}

/*The function DecK perfroms a rotation cipher decryption on an inputted char string of characters
The char input is a string of inputted characters that has been encrypted using a rotation cipher
The int input is the key and is the amount of spaces that the encrypted letters have rotated from their original values (Eg. if A goes to B then key = 1)
It returns a void value as this function prints the decrypted message string.
This function takes an encrypted message and the rotation key used for encryption and decrypts the message by moving the letter back to their original places
This means that if the enecryption key used was 1 then the letter B decrypted would be A
This function does not have any data type restrictions but string length is limited to how much the computer/website can take without crashing
 */
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
//+26 was done to ensure that when key is taken away from the value it still produces a value that is postive and can be used by the function
//modulus 26 makes produces the remainder of the created value divided by 26 and 65 is added to produce a the decrypted ASCII value
        }
         
    }
    printf("This message decrypted is: %s\n", message); //prints the decrypted message
}



#include <stdio.h>
#include"Head.h"

void EncK(char message[], int key); //Function Prototype for the Function EncK (Encyption for K)
int main()
{
    char message[] = "wWxXyY"; //This is the inputted message that will be Encrypted
    int key =  100; 
    /* key is the key for the encryption.
    This key dictates the movement of every letter in the Rotation Cipher Encryption.
    For Example; if the key is 1 every letter moves 1 space.
    This means that if key =  1 then A becomes B.
    */
    EncK(message, key);//Function taking the message and key and encrypting the message
    
}

/* The function EncK encrypts a message using a rotation cipher
The char (character) input is the message to be encrypted in English Letter that can be upper or lower case.
The int (interger) input is the key and is the amount of spaces each letter rotates.
The return value is void as this function does not return a value but rather prints the new encrypted message.
The function performs a rotation cipher on an inputted message.
A rotation cipher is a means for encrypting messages that rotates the alphabet used within the message.
This means that every letter moves a predetermined amount of spaces through the alphabet.
This means if the rotation key is 1 A=B, B=C, ....., Z=A.
Strings can be of any length to be used in this function as long as they are not too long for the computer to process.
The key inputted must be postivie otherwise the function will not produce the correct encrypted values.
Although positive encryption can be used to get the same encryption value as a negative key.
Eg. If key = -1 then B=A and if key = 25 B=A.
Punctiation and other symbols are not encrypted, only letters.
Lowercase letters are transformed into upper case letter.
 */
void EncK(char message[], int key) //Function definition
{
     printf("Inputted message was: %s\n", message); //This prints the original message so it can be reviewed
     int index; //declares a varibale index that will be used as the pointer for the message array to point at individual letters.
     for(index = 0; message[index] != 0; index++) //starts a for loop that declares index as 0 and if message[index] does not equal 0 it will continue to loop
     //When it reaches the end of the loop it repeats and increases the index. This will stop once the index reaches the end of the array.
     {
         if(message[index] >= 97 && message[index] <= 122) //checks to see if any characters used are lower case letters.
         {
             message[index] = message[index] - 32; //if they are lower case letters -32 turns them into upper case (as seen on ASCII table)
         }
     }
     for(index = 0; message[index] !=0; index++) //performs the same as the for loop above, cycles through the message until the end.
     {
         if(( message[index] < 65) || (message[index] > 90 && message[index] < 97) || (message[index] > 122)) //this if statement determines if characters used are punctuation or symbols
         {
       //do nothing to punctuation or symbols 
         }
         else //perform this loop on letters
         {
             message[index] = ((message[index] - 65) + key ) % 26 + 65; 
 /*the message[index] - 65 is used to assign the letters of the alphabet a number between 0 and 25
 The key is then added to move this value up and then the modulus of this new value is taken (the remainder of the division of the number by 26) and 65 is added to produce the new ASCII value
 this modulus is used to ensure that no matter how high the key is, the produced value will not exceed 25 and the produce ASCII value does not exceed 90. The remainder of the division of a number by 26 can only be between 0 and 25.
 For example message[index] = 65 and key = 100, 65 - 65 = 0, 0 + 100 = 100, 100 % 26 = 22, 22 + 65 = 87, 87 = W.
 this equation sets every character in the array to a new encrypted character
 */
         }
         
     }
     printf("The Encrypted message is: %s\n", message); //new encrypted message is printed
} //no return value as function produces a void return value