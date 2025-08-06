/*The program shows how to enter strings in an array.
A string in itself a array of characters!
Therefore, a string of array uses 2D array*/

#include <stdio.h>
#include <string.h>

int main(void){
    char names[3][25] = {0}; //initialises array as 0 to prevent garbage value
    int numRows = sizeof(names) / sizeof(names[0]); //to find number of rows in an array; in this case num of Strings

    for(int i = 0; i < numRows; i++){
        printf("Enter a name: ");
        fgets(names[i], sizeof(names[i]), stdin); //fgets uses <string.h> header file. Stores one name (charArray) in given row/place
        names[i][strlen(names[i]) - 1] = '\0'; //strlen(names[i] - 1) = length of first string - 1; which is last char in string
    }

    printf("\nNames entered are:\n");
    for(int i = 0; i < numRows; i++){
        printf("%d. %s\n", (i + 1), names[i]);
    }

    return 0;
}