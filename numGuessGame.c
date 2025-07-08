/* The program aims to create a game
   which will produce a random number between 1-100
   The user will be asked to guess the number.
   The program continues till the correct number is guessed*/

#include <stdio.h>
#include <stdlib.h> // contains rand func.
#include <time.h>   // contains time func.

void guessNum(int randNum, int minNum, int maxNum);

int main(void){

    int min = 1;
    int max = 100;
    srand(time(NULL)); // uses OS time value to provide different seed value to rand func.
    int randNumber = (rand() % (max - min + 1)) + min; //formula to make sure rand func. falls within range

    printf("Lets play a number guessing game!!\n\n");
    guessNum(randNumber, min, max);
}

void guessNum(int randNum, int minNum, int maxNum){
    int guess;
    int numTry = 0;
    do{
        printf("Guess a number between %d - %d : ", minNum, maxNum);
        scanf("%d", &guess);

        if(guess > randNum){
            printf("Guessed high!!! Try again.\n");
        }
        else if(guess < randNum){
            printf("Guessed Low!!! Try again\n");
        }
        else if(guess == randNum){
            printf("Guessed correct!!!\n");
        }
        numTry++;
    }while(guess != randNum);

    printf("The correct answer is: %d\n", randNum);
    printf("You tried a total of %d times.\n", numTry);
}