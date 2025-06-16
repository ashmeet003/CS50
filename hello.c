#include <string.h> //used for strlen function
#include <stdio.h> //standard io header file
//header file : contains functionality which comes with the language
// gives access to libraries
int main(void)
{
    //string answer=get_string("whats your name? ");
    //printf("hello, world. Name is %s\n", answer);
    char name[100], fname[100];
    printf("hello, world.\nWhat is your name?\n");
    scanf("%s", name);
    printf("Hello, my name is %s\n",name);
    printf("Enter Full name: ");
    getchar(); //gets the new line character from input buffer
    fgets(fname, sizeof(fname), stdin);// use this to get string with a space
    printf("My full name is %s\n", fname); //fname holds \n character in input buffer hence the next line is added
    printf("...................................................\n");
    fname[strlen(fname)-1]='\0'; //to remove last character from input before so it could execute normally
    printf("Full name after removing last next line char in input buffer: %s", fname);
    printf("........."); //output comes like "fname...." hence last char removed

}