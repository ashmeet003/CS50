/* 
    The program encrypts messages using a substitution cipher.
    A key of 26 letters is entered through command line
        Characters should be all alphabets and non repeating letters.
    For example: 
        Key: NQXPOMAFTRHLZGECYJIUWSKDVB
        Means: A = N; B = Q; C = X;.....; Z = B
        Plaintext:  Hello
        CipherText: Folle
    
    Execution: 
        gcc substitution.c -o substitution
        ./substitution.exe NQXPOMAFTRHLZGECYJIUWSKDVB //or any other sequence of 26 alpha's
*/

#include <stdio.h>
#include <ctype.h>  // for toupper(), tolower(), isalpha()
#include <libgen.h> // for basename
#include <string.h> //for strlen()

int only_alphas(char* key); //checks if string is only alphabets; 26 in length; and non repeating
char substitute(char single, char* key); //substitutes the char accord to key

int main(int argc, char* argv[]){

    char *program_name = basename(argv[0]); // rather than printing the whole path, basename stores only last file name

    if(argc != 2){ //if more than 1 input is passed, error is shown; program ends
        printf("Usage: ./%s <key>\n", program_name);
        return 1;
    }

    char* key = argv[1];

    if(only_alphas(key)){ //if right sequence of alphabets in key

        char plaintext[100];
        printf("plaintext:  ");
        fgets(plaintext, sizeof(plaintext), stdin);
        plaintext[strlen(plaintext) - 1] = '\0';
        printf("ciphertext: ");

        // passes key and single character to substitute() and prints the returned character
        for(int i = 0; plaintext[i] != '\0'; i++){
            char single = substitute(plaintext[i], key);
            printf("%c", single);
        }
        printf("\n");
    }
    else{ //if key is wrong
        printf("Usage: ./%s key\n", program_name);
        return 1;
    }

    return 0;
}

int only_alphas(char* key){

    if(key == NULL || *key == '\0'){ // if null or empty string
        return 0 ;
    }
    if(strlen(key) != 26){ //if length is not 26
        return 0;
    }

    for(int i = 0; key[i] != '\0'; i++){
        if(!isalpha(key[i])){ //if not an alphabet
            return 0;
        }
        int count = 0; //counts number of same character present in sequence, if any
        for(int j = 0; key[j] != '\0'; j++){ //checks if a alphabet is repeated in sequence
            if(key[j] == key[i]){
                count++;
            }
        }
        if(count > 1){ //if any alphabet is repeated; return false
            return 0;
        }
    }
    return 1; //everything is right
}

char substitute(char single, char* key){

    // if single character is alphabet, it gets substituted else char is simply returned
    // The logic goes that we need to know single character' position in alphabet sequence (0-25)
    // This position is compared to key given
    // the letter in key present in that position is used for substitution
    // Then, the logic checks is single character is originally uppercase or lowercase
    // According to the single character' case, the case of letter in key is changed and returned back

    if(isalpha(single)){ // if alpha
        char upperSingle = toupper(single); // upperSingle stores uppercase of single
        int flagPos = upperSingle - 65; // gives position in (0-25), eg. upperCase = 'B'; 'B' - 65 = 1
        char sub = key[flagPos]; // sub stores key' value in position flagPos
        if(isupper(single)){ //if upper single = uppercase key value
            single = sub;
        }
        if(islower(single)){ //if lower single = lowercase key value
            single = tolower(sub);
        }
    }
    
    return single; // single is returned
}