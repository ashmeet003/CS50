/*
The program aims to create following patterns:
1.

    #
   ##
  ###
 ####
#####

2.

    #  #
   ##  ##
  ###  ###
 ####  ####
#####  #####
*/

#include <stdio.h>

void singlePyramid(char pattern, int height);
void doublePyramid(char pattern, int height);

int main(){

    int height = 0;
    int option = 0;
    char pattern = '#';

    printf("\nLets create a pyramid pattern using #\n\n");
    printf("Enter option from 1 or 2 to make single or double pyramids: ");
    scanf("%d", &option);
    
    int result; // to store scanf return value

    do {
        printf("Enter the height: ");

        // Try to read integer
        result = scanf("%d", &height); //scanf()returns number of items successfully read

        // If input is invalid (scanf fails)
        if (result != 1) {
            printf("Invalid input! Please enter a positive number.\n");

            // Clear leftover characters from input buffer
            while (getchar() != '\n');
            height = 0; // force loop to run again
        }
        else if (height < 1) {
            printf("Invalid input! Please enter a number > 0.\n");
        }

    } while (height < 1);

    if(option == 1){
        singlePyramid(pattern, height);
    }
    if(option == 2){
        doublePyramid(pattern, height);
    }

    

    return 0;
}

void singlePyramid(char pattern, int height){

    for(int i = 1; i <= height; i++){ //works for height of pyramid
        for(int j = i; j < height; j++){ //adds spaces till (height-i)
            printf("%c", ' ');
        }
        for(int k = 1; k <= i; k++){ // adds pattern in left space after spaces
            printf("%c", pattern);
        }
        printf("\n");
    }

}
void doublePyramid(char pattern, int height){

    for(int i = 1; i <= height; i++){ //works for height
        for(int j = i; j < height; j++){ //prints first spaces of row
            printf("%c", ' ');
        }
        for(int k = 1; k <= i; k++){ //then prints pattern for first half of row
            printf("%c", pattern);
        }
        printf("  "); //adds two spaces
        for(int k = 1; k <= i; k++){ //adds pattern for second half of row
            printf("%c", pattern);
        }
        printf("\n");
    }
}
