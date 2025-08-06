/*Program aims to create a program to ask for input.
User can enter either Y or N
Else loop is used to ask for input again*/

#include <stdio.h>

int main(void){
    char response;
    printf("Would you like to continue?\n");
    do{
        printf("Enter Y for yes and N for no: ");
        scanf(" %c", &response);
        if(response == 'N' || response == 'n'){ //if user chooses no exit the program
            printf("You exited the program!\n");
            break;
        }
    }while(response != 'N' || response != 'n'); //if user enters anything other than no, program cont.
}