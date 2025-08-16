/*
    The program is based on readability test: developed over the years that define
    formulas for computing the reading level of a text.
    This test is based on: Coleman-Liau index
        index = 0.0588 * L - 0.296 * S - 15.8
    where L is the average number of letters per 100 words in the text, 
    and S is the average number of sentences per 100 words in the text.

    Example:
        Would you like them here or there? 
        I would not like them here or there.
        I would not like them anywhere.
        Output: Grade 2
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h> //used for toupper()
#include <math.h> //used for round();

int main(){

    char sentence[1000];
    printf("Enter your sentence: ");
    getchar();
    fgets(sentence, sizeof(sentence), stdin);
    int strLen = strlen(sentence);
    sentence[strLen - 1] = '\0'; //adds nul to last position instead of new line character

    int numWords = 1; //stores number of words in the string assuming str has atleast 1 word
    double sumNumSen = 0; //total number of sentences ; double is imp for later calculation for S;
    double sumNumLet = 1; //total number of letters ; double is imp for later calculation for S
    //P.S. sum of items remain same regardless the denominator for calculating average

    for(int i = 0; i < strLen; i++){
        sentence[i] = toupper(sentence[i]);
        if(sentence[i] == ' '){ //if a space is found; a number is added
            numWords++;
        }
        else if(sentence[i] == '.' || sentence[i] == '?' || sentence[i] == '!'){// marks end of sentence
            sumNumSen += 1; // adds number of sentences
        }
        else if(sentence[i] >= 'A' && sentence[i] <= 'Z'){ //calculates number of letters
            sumNumLet += 1; // adds number of letters
        }
    }


    //marks start of implementing the formula
    double L = (sumNumLet/ numWords) *100.00;  // calculates average number of letters per 100 words
    double S = (sumNumSen / numWords) *100.00; // calculates average number of sentences per 100 words
    double index = round((0.0588 * L) - (0.296 * S) - 15.8);  // Coleman-Liau index

    //prints output
    if(index < 1){
        printf("Before Grade 1\n");
    }
    if(index >= 1 && index < 16){
        printf("Grade %d\n", (int)(index));
    }
    if(index >= 16){
        printf("Grade 16+\n");
    }

}