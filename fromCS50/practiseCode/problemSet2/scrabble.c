/*
    The scrabble game works on comparing the words to know who scored the most.
    Each letter has an assigned point. The sum of these points determines the winner.
    Example:
            Player 1: Question?
            Player 2: Question!
            Tie!

            Player 1: COMPUTER
            Player 2: science
            Player 1 wins!
*/

#include <stdio.h>
#include <ctype.h> //used for toupper()

int main(){

    char letters[] = {'A', 'B', 'C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int point[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    int arrSize = 26; //size of letters&point array
    
    char word1[50], word2[50];
    printf("Enter Your Words:\n");
    printf("Player 1: ");
    scanf("%s", word1);
    printf("Player 2: ");
    scanf("%s", word2);

    int score1 = 0, score2 = 0;

    int n = 0; //position of leter in entered word for while loop
    while(word1[n] != '\0'){

        char letter = toupper(word1[n]); //converts letter to upperCase

        for(int i = 0; i < arrSize; i++){ //compares letter to letters[]
            if(letter == letters[i]){
                score1 += point[i]; //if same, adds pointValue at same position in point[]
            }
        }
        n++;
    }
    
    n=0; // reInitializes n to 0 for while()
    while(word2[n] != '\0'){
        
        char letter = toupper(word2[n]);

        for(int i = 0; i < arrSize; i++){
            if(letter == letters[i]){
                score2 += point[i];
            }
        }
        n++;
    }

    //compares the scores
    if(score1 > score2){
        printf("Player 1 wins!!");
    }
    else if(score2 > score1){
        printf("Player 2 wins!!");
    }
    else{
        printf("Tie!!");
    }

    return 0;
}