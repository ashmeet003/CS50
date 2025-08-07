/*
    The program explains pointer and its use
    Both the regular way of passing value(callByValue) and pointer way(callByReference) is shown.
*/
#include <stdio.h>

void passByValue(int age);
void passByReference(int *age);

int main(){

    int age = 25;
    int *pAge = &age;

    printf("%p\n%p\n\n", &age, pAge); //shows &age is address for variable and pAge is pointer holding address

    passByValue(age);
    printf("Age after pass by value: %d\n", age);

    passByReference(&age); //could also do (*pAge)
    printf("Age after pass by reference: %d\n", age);

    return 0;
}

void passByValue(int age){
    age++;
}

void passByReference(int *age){
    (*age)++; //bracket is needed else increment would proceed dereferencing
}