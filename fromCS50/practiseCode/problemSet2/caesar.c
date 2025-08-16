/**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strlen
#include <ctype.h>  // For isdigit
#include <libgen.h> // For basename


int only_digits(char *str);
char rotate(int num, char single);

int main(int argc, char *argv[]){
    char *program_name = basename(argv[0]);
    if(argc != 2){
        printf("Usage: ./%s <number>\n", program_name);
        return 1;
    }

    char *inputArg = argv[1];
    int num = 0;
    if(only_digits(inputArg)){
        num = atoi(inputArg);
    }
    else{
        printf("Input is not a number. Usage: ./%s <number>\n", program_name);
        return 1;
    }
    char plaintext[100];
    char ciphertext[100];
    printf("plaintext:  ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strlen(plaintext) - 1] = '\0';

    printf("ciphertext: ");
    for(int i = 0; plaintext[i] != '\0'; i++){
        
        
        char single = rotate(num, plaintext[i]);
        printf("%c", single);
    }
    printf("\n");
    return 0;
}

int only_digits(char *str){
    if (str == NULL || *str == '\0') {
        return 0; // Empty or NULL string is not numeric
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
        return 0; // Not a digit
        }
    }
    return 1;
}

char rotate(int num, char single){
    if(single >= 97 && single <= 122){
        int alphaPos = single - 97;
        int numRot = (alphaPos + num) % 26;
        single = (char)(97 + numRot);
    }
    if(single >= 65 && single <= 90){
        int alphaPos = single - 65;
        int numRot = (alphaPos + num) % 26;
        single = (char)(65 + numRot);
    }

    return single;
}