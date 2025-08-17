/*
    The program is based on encryption and asks for a number, known as key, from the user through command line.
    Unencrypted text is generally called plaintext. Encrypted text is generally called ciphertext. And the secret used is called a key.
    if p is the character in plaintext and k is key, then c in ciphertext would be computed as:
    c = (p + k) % 26;

    The program also works on asking only integer value through command line else prints error message.
    execution:
        gcc caesar.c -o caesar
        ./caesar.exe 13 //or any other number
*/

#include <stdio.h>
#include <stdlib.h> // For atoi()
#include <string.h> // For strlen()
#include <ctype.h>  // For isdigit()
#include <libgen.h> // For basename()


int only_digits(char *str); //returns true if only number is passed through command line
char rotate(int key, char single); // returns rotated character according to key

int main(int argc, char *argv[]){

    char *program_name = basename(argv[0]); // rather than printing the whole path, basename stores only last file name

    if(argc != 2){ //if more than 1 input is passed, error is shown; program ends
        printf("Usage: ./%s <number>\n", program_name);
        return 1;
    }

    //else program checks if a number is passed or not
    char *inputArg = argv[1];
    int key = 0;
    if(only_digits(inputArg)){ //if a number is passed
        key = atoi(inputArg); //string is converted to int and stored in key
    }
    else{ //else error is shown
        printf("Input is not a number. Usage: ./%s <number>\n", program_name);
        return 1;
    }

    //encryption program starts
    char plaintext[100];
    printf("plaintext:  ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strlen(plaintext) - 1] = '\0';
    printf("ciphertext: ");

    //passes each character of plaintext to rotate function and returned value is printed
    for(int i = 0; plaintext[i] != '\0'; i++){
        char single = rotate(key, plaintext[i]);
        printf("%c", single);
    }
    printf("\n");

    return 0;
}

int only_digits(char *str){ //checks for number input; 0 = false; 1 = true

    if (str == NULL || *str == '\0') {
        return 0; // Empty or NULL string is not numeric
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) { //isdigit() checks each char for a number
        return 0; // Not a digit
        }
    }

    return 1;
}

char rotate(int key, char single){ //rotates character if an alphabet

    // the logic is based on alphabet' sequence from 0-25 (26 digits)
    // if character is an alphabet, A' ASCII value is subtracted from char' ASCII...
    // This gives us char' position in regular Alpha's sequence (0-25)
    // encryption' formula is applied to know char' rotated position in sequence (0-25)
    // Based on rotated position, rotated char' ASCII value is calculated
    // other characters than alphabets are simply returned

    if(single >= 97 && single <= 122){   // if lower case
        int alphaPos = single - 97;      // gives position in (0-25)
        int num = (alphaPos + key) % 26; // rotated character' position is calculated
        single = (char)(97 + num);       // added to 97 to calculate alpha' position in ASCII range
    }
    if(single >= 65 && single <= 90){    // if upper case
        int alphaPos = single - 65;
        int num = (alphaPos + key) % 26;
        single = (char)(65 + num);
    }

    return single;
}