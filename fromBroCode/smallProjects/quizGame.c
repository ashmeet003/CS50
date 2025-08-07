/*
 The program is based on quiz game!
 User is asked questions and given options to choose from 
 and asked to enter the correct option Character
 
 questions, options are stored using 2D array and answerKey using 1D array
 
 The answer choice entered by user is compared to answer key to get total score
*/

#include <stdio.h>

int main(void){

    char questions[][200] = {"When is international women's day celebrated?",
                             "When is international men's day celebrated?",
                             "When is World Health Day celebrated?"};
    
    char options[][200] = {"A. March 8\nB. May 6\nC. April 11\nD. February 20\n",
                           "A. August 14\nB. September 4\nC. November 19\nD. July 9\n",
                           "A. March 7\nB. July 8\nC. April 9\nD. April 7\n"};

    char ansKey[] = {'A', 'C', 'D'};

    int numRows = sizeof(questions) / sizeof(questions[0]); //num of rows / num of questions
    int count = 0; //to count total score for user

    printf("****** Welcome to the Quiz ******\n\n");
    for(int i = 0; i < numRows; i++){
        char choice;
        printf("%d. %s\n", (i+1), questions[i]);
        printf("Your Options are:\n");
        printf("%s", options[i]);
        printf("Enter your choice from A-D: ");
        scanf(" %c", &choice);

        //Works to convert choice to Upper Case if in case user enters lowerCase character
        if(choice >= 'a' && choice <= 'z'){
            choice = choice - 32;
        }

        if(choice == ansKey[i]){ //compares choice to answer Key
            printf("Correct answer!\n\n");
            count++;
        }
        else{
            printf("Wrong answer!\n\n");
        }
    }

    printf("Quiz Over!\n\n");

    printf("********************************************************\n\n");
    printf("Answer Key is:\n\n"); //prints answer key
    for(int i = 0; i < numRows; i++){
        printf("%d. %s\n", (i+1), questions[i]);
        printf("Options were:\n");
        printf("%s", options[i]);
        printf("Answer: %c\n\n", ansKey[i]);
    }
    printf("********************************************************\n\n");

    printf("Your total score is: %d out of %d.\n\n", count, numRows); //tells total score
    printf("\n****** Thank You for participating in the Quiz ******\n");

    return 0;
}