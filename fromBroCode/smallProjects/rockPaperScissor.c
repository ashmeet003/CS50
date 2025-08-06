/*
    Rock Paper Scissor Game:
    The game works to ask user input:
        validate the input or ask again.
    compare the user input to computer generated random number:
        This determines the Winner of the round.
    5 Rounds in total are played and a winner is declared.
*/

#include <stdio.h>
#include <stdlib.h> //used for rand()
#include <time.h>   // used for time()

int getUserChoice(); //gets and validates user input
int getCompChoice(); //gets computer generated random number between 1-3
void checkWinner(int userChoice, int compChoice); //checks winner and keeps count for user and computer
int COUNTUSER = 0; //used as count for user
int COUNTCOMP = 0; //used as count for computer

int main(void){
    printf("********** ROCK PAPER SCISSOR **********\n\n");
    
    printf("Choose an Option: \n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissor\n");
    
    //do while loop is used to continue the game unless any one player scores 5
    do{
        int userChoice = getUserChoice();
        int compChoice = getCompChoice();
        checkWinner(userChoice, compChoice);
    }while(COUNTUSER < 5 && COUNTCOMP < 5);
    

    //final winner is declared
    if(COUNTUSER > COUNTCOMP){
        printf("\nWinner of the game is: User(YOU)!!!!\n");
    }
    else{
        printf("\nWinner of the game is: Computer!!!!\n");
    }
    
}

int getUserChoice(){
    int choice=0;
    do{
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("You chose Rock!\n");
                break;
            case 2:
                printf("You chose Paper!\n");
                break;
            case 3:
                printf("You chose Scissor!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }while(choice < 1 || choice > 3);
    return choice;
}

int getCompChoice(){
    srand(time(NULL)); //seed value of rand() is optimized according to current system time
    int randNumber = (rand() % 3) + 1; //random number between 1-3 is generated
    switch(randNumber){
        case 1:
            printf("Computer chose Rock!\n");
            break;
        case 2:
            printf("Computer chose Paper!\n");
            break;
        case 3:
            printf("Computer chose Scissor!\n");
            break;
    }
    return randNumber;
}

void checkWinner(int userChoice, int compChoice){
    if(userChoice == 1 && compChoice == 2){
        printf("Computer Wins!\n");
        COUNTCOMP++;
    }
    else if(userChoice == 1 && compChoice == 3){
        printf("You Win!\n");
        COUNTUSER++;
    }
    else if(userChoice == 2 && compChoice == 1){
        printf("You Win!\n");
        COUNTUSER++;
    }
    else if(userChoice == 2 && compChoice == 3){
        printf("Computer Wins!\n");
        COUNTCOMP++;
    }
    else if(userChoice == 3 && compChoice == 1){
        printf("Computer Wins!\n");
        COUNTCOMP++;
    }
    else if(userChoice == 3 && compChoice == 2){
        printf("You Win!\n");
        COUNTUSER++;
    }
    else{
        printf("It is a draw!\n");
    }
}