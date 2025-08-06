/*To make a shopping cart program
Program would ask for the name of the item, price of item and total number of items in the cart
Returning the total price of your shopping cart*/
#include <stdio.h>
#include <string.h>
int main(void){
    char item[50]="";
    float price=0.0f; //f here tells it is a floating point number
    int numItems=0;

    printf("Which item would you like to buy? :");
    fgets(item, sizeof(item), stdin);
    item[strlen(item)-1]='\0';

    printf("Enter the price of each: $");
    scanf("%f", &price);

    printf("Enter number of items in the cart: ");
    scanf("%d", &numItems);

    printf("..........................................\n");
    
    printf("You have %d %s(s) in your cart with each priced $%.2f\n", numItems, item, price);
    printf("Your total price to be paid is: $%.2f\n", (numItems*price));
}