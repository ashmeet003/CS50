/*Program to input a number as option for specific pattern
  Option 1: Create a table upto 10
  Option 2: Create a pattern according to rows, column, and character
  If invalid option is entered, ask again
  Use functions for options*/

#include <stdio.h>
void tables();
void charPattern();

int main(void){
    int option;
    do{
        printf("Enter 1 for Tables or 2 for char pattern: ");
        scanf("%d", &option);
    }while(option != 1 && option != 2);
    
    if(option == 1){
        tables();
    }
    else if(option == 2){
        charPattern();
    }
}

void tables(){
    for(int i=1; i<=10; i++){
        for(int j=1; j<=10; j++){
            printf("%3d ", i*j); //prints digits with each having 3 digit space for alignment
        }
        printf("\n");
    }
}

void charPattern(){
    int row = 0, column = 0;
    char character;
    printf("Enter the number of rows for pattern: ");
    scanf("%d", &row);
    printf("Enter the number of columns for pattern: ");
    scanf("%d", &column);
    printf("Enter character for pattern: ");
    scanf(" %c", &character);

    for(int i=1; i<=row; i++){
        for(int j=1; j<=column; j++){
            printf("%c", character);
        }
        printf("\n");
    }
}