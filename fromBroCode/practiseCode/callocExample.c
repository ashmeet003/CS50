/*
    This program explains use of calloc()
    calloc() initialises every memory reserved to 0, else, those pointers would hold garbage value.
    This results in less bugs.
*/

#include <stdio.h>
#include <stdlib.h> //contains calloc()

int main(){

    int inputNum = 0; //number of input
    printf("Enter the number of players: ");
    scanf("%d", &inputNum);

    int *scores = calloc(inputNum, sizeof(int)); //clloc needs #Input and size of input as arguments

    if(scores == NULL){ //tests if pointer is null already
        printf("Memory Allocation failed!");
        return 1;
    }

    for(int i = 0; i < inputNum; i++){
        printf("Enter score for player#%d: ", (i + 1));
        scanf("%d", &scores[i]);
    }

    printf("*******************************************\n");
    printf("Scores are:\n\n");
    for(int i = 0; i < inputNum; i++){
        printf("Score for player#%d: %d\n", (i + 1), scores[i]);
    }

    free(scores); //frees the memory
    scores = NULL; //deems pointer as NULL

    return 0;
}