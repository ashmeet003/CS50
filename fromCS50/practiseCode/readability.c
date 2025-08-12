#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char sentence[1000];
    printf("Enter your sentence: ");
    getchar();
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strlen(sentence) - 1] = '\0';

    int numWords = 0;

    for(int i = 0; i < (strlen(sentence) - 1); i++){
        sentence[i] = toupper(sentence[i]);
        if(sentence[i] == ' '){
            numWords++;
        }
    }
    numWords += 1;
    int perHund = 0;

    if(numWords > 100){
        perHund = numWords / 100;
    }
    perHund += 1;

    int avgNumLet[perHund];
    int avgNumSen[perHund];
    int posSent = 0;
    int posLet = 0;
    numWords = 1;
    for(int i = 0; i < (strlen(sentence) - 1); i++){
        if(sentence[i] == ' '){
            numWords++;
        }
        else if(sentence[i] == '.' || sentence[i] == '?' || sentence[i] == '!'){
            avgNumSen[posSent] += 1;
        }
        else if(sentence[i] >= 'A' && sentence[i] <= 'Z'){
            avgNumLet[posLet] += 1;
        }
        if(numWords == 100){
            posSent++;
            posLet++;
            numWords = 1;
        }
    }
    int L = 0, S = 0;
    int sumL = 0, sumS = 0;
    for(int i = 0; i < perHund; i++){
        sumL += avgNumLet[i];
        sumS += avgNumSen[i];
    }
    L = sumL / perHund;
    S = sumS / perHund;

    int index = 0.0588 * L - 0.296 * S - 15.8;

    if(index < 1){
        printf("Before Grade1\n");
    }
    if(index >= 1 && index < 16){
        printf("Grade %d\n", index);
    }
    if(index >= 16){
        printf("Grade 16+\n");
    }

}