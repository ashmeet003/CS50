/*
    This program shows use of realloc().
    First, malloc() is used to reserve memory and dynamically allocate values.
    Next, a new memory is reserved for new value needed.
    Old memory is reallocated with new, and new values are added to memory
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int inputNum = 0;
    printf("Enter the number of prices: ");
    scanf("%d", &inputNum); //initial number of input

    float *prices = malloc(inputNum * sizeof(float)); //reserves memory in heap

    if(prices == NULL){ //checks if memory is successfully allocated; avoids dangling pointer
        printf("Memory couldn't be allocated!\n");
        return 1;
    }

    for(int i = 0; i < inputNum; i++){ //asks user for initial set of values
        printf("Enter the price #%d: $", i + 1);
        scanf("%f", &prices[i]);
    }

    //reallocation starts here
    int newInputNum = 0;
    printf("Enter the  new number of prices: "); //asks for new total number of values
    scanf("%d", &newInputNum);
    float *temp = realloc(prices, (newInputNum * sizeof(float))); //reserves new temporary memory

    if(temp == NULL){ //checks if new memory is allocated
        printf("New memory couldn't be allocated!\n");
    }
    else{ //if YES
        prices = temp; //pointer stores new memory
        temp = NULL; //temp pointer is deemed NULL, if needed for future use

        for(int i = inputNum; i < newInputNum; i++){ //asks new value from the last value added
            printf("Enter the price #%d: $", i + 1);
            scanf("%f", &prices[i]);
        }
    }

    // prints new total values
    printf("\nThe prices are:\n");
    for(int i = 0; i < newInputNum; i++){
        printf("$%.2f ", prices[i]);
    }

    free(prices); //frees memory
    prices = NULL; //pointer is deemed NULL after use

    return 0;
}