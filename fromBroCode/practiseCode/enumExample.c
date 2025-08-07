/*
    The program is meant to showcase the use of enum (short of enumerations)
    and how it improves program's readability instead of using numbers
    ***enum are set of named integer constant***
*/

#include <stdio.h>

typedef enum{
    SUCCESS, PENDING, CANCELLED //default value of 1st constant is 0 and so on
}Status; //enum typedef is used and named Status (capital S)

void checkStatus(Status status);

int main(){
    Status status = SUCCESS; //variable is named status(lower case s) and is assigned SUCCESS constant
    checkStatus(status);
}

void checkStatus(Status status){ //status holds value as SUCCESS(also 0 in behind the scene)
    switch(status){ //status is checked to match value
        case SUCCESS:
            printf(" Connection is successful!");
            break;
        case PENDING:
            printf("Connection is Pending! Please Wait.");
            break;
        case CANCELLED:
            printf("Connection is Cancelled! Sorry.");
            break;
    }
}