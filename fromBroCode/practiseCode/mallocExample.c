/*
    The program is designed to show the use of malloc()
    a temporary place to hold user input; 
    specifically helpful if size needed is not known ahead of time
*/

#include <stdio.h>
#include <stdlib.h> //neded for malloc()

int main(){

    int inputNum = 0; //needed to specify number of input needed
    printf("Enter the number of grades: ");
    scanf("%d", &inputNum);

    char *grades = malloc(inputNum * sizeof(char)); //calculates size needed to be reserved according to inputNum and data type

    if(grades == NULL){ //makes sure pointer is not NULL
        printf("Memory allocation failed!\n");
        return 1;
    }

    //gets user input
    for(int i = 0; i < inputNum; i++){
        printf("Enter grade for #%d: ", (i + 1));
        scanf(" %c", &grades[i]);
    }

    //prints the user input
    printf("***********************************\n");
    printf("\nGrades are:\n\n");
    for(int i = 0; i < inputNum; i++){
        printf("Grade for #%d: %c\n", (i + 1), grades[i]);
    }

    free(grades); // frees/returns the reserved memory: frees malloc()
    grades = NULL; //since pointer was not NULL(checked before); specifies the pointer as NULL; avoids dangling pointer

    return 0;
}