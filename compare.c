#include <stdio.h>
int main(void){
    int option;
    printf("Enter 1 to compare numbers or Enter 2 to compare letters: ");
    scanf("%d", &option);
    if(option == 1){
        int x,y;
    printf("Enter first number: ");
    scanf("%d", &x);
    printf("Enter second number: ");
    scanf("%d",&y);
    if(x>y){
        printf("%d is greater than %d", x, y);
    }
    else if(x<y){
        printf("%d number is greater than %d", y, x);
    }
    else{
        printf("Both numbers are equal");
    }
    }
    else if(option == 2){
        char x;
        printf("Do you agree? enter 'y' or 'n' : ");
        scanf(" %c", &x);//added extra space before %c
        if(x == 'y' || x == 'Y'){
            printf("You agreed");
        }
        if(x=='n' || x=='Y'){
            printf("You disagreed");
        }
        else{
            printf("You entered wrong letter!");
        }
    }
    
}